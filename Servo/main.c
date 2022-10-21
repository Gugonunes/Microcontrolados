#include <msp430.h> 

void ini_uCon(void);
void ini_P1_P2(void);
void ini_Timer0_PWM(void);
void ini_Timer1(void);

int main(void)
{
    ini_uCon();
    ini_P1_P2();
    ini_Timer0_PWM();
    ini_Timer1();

    do{

    }while(1);
	
}
#pragma vector=PORT1_VECTOR
__interrupt void RTI_Porta_1(void){

    // 1 - Desabilita int. da entrada
    P1IE &= ~BIT4;

    // 2 - Inicia temporizador
    TA0CTL |= MC0;
}
void ini_P1_P2(void){
    /* PORTA 1
     *     P1.0 - N.C. - saida em nivel baixo;
     *     P1.1 - N.C. - saida em nivel baixo;
     *     P1.2 - N.C. - saida em nivel baixo;
     *     P1.3 - S2.  - entrada com resistor de pull-up;
     *     P1.4 - CH_A - entrada com resis. de pull-up e int. por borda de descida;
     *     P1.5 - CH_B - entrada com resis. de pull-up;
     *     P1.6 - LED VD - saida em nivel baixo;
     *     P1.7 - N.C. - saida em nivel baixo;
     */
    P1DIR = ~(BIT4 + BIT5);
    P1REN =  BIT4 + BIT5;
    P1OUT =  BIT4 + BIT5;
    P1IES = BIT4;
    P1SEL |= BIT6;
    P1IFG = 0;
    P1IE = BIT4;

    P1DIR = 0XFF;
    P2OUT = 0;

}

void ini_Timer0_PWM(void){
    /* f_pwm = 50 Hz
     *
     * BLOCO CONTADOR:
     *  Clock: SMCLK ~ 16 MHz
     *      FDiv = 8;
     *  Modo contagem: UP
     *  Int. contador: nao utilizada
     *
     * MODULO 0 - Freq. do sinal
     *  Funcao: nativa = comparacao
     *  TA1CCR0 = (temp*SMCLK)/Fdiv = ((1/50)*16000000)/8 - 1= 39999 -> 39999 é menor que 2^16, então pode ser usado;
     *  Int.: DESabilitada
     *
     * MODULO 1 - RC do sinal 1 - RC1 inicial = 0%
     *  Funcao: nativa = comparacao
     *  TA1CCR1 = 0;
     *  Int.: DESabilitada
     */
    TA0CTL = TASSEL1 + MC0 + ID0 + ID1; //IDS Setam o fator de divisão
    TA0CCTL0 = OUTMOD0 + OUTMOD1 + OUTMOD2;
    TA0CCR0 = 39999;
    TA0CCR1 = 2000; // -> 5% de (39999 + 1)
}

void ini_Timer1(void){
    /* t_deb = 2 ms
     *
     * BLOCO CONTADOR:
     *  Clock: SMCLK ~ 2 MHz
     *      FDiv = 8;
     *  Modo contagem: Inicialmente parado
     *  Int. contador: nao utilizada
     *
     * MODULO 0
     *  Funcao: nativa = comparacao
     *  TA0CCR0 = (temp*SMCLK)/Fdiv = (0,002*2000000)/1 - 1= 3999;
     *  Int.: Habilitada
     */
    TA1CTL = TASSEL1 + ID0 + ID1;
    TA1CCTL1 = CCIE;
    TA1CCR0 = 3999;
}

#pragma vector=TIMER1_A0_VECTOR
__interrupt void RTI_TIMER1(void){
    //parada do contador
    TA1CTL &= ~MC0;

    if ((~P1IN) & BIT4){
        if( P1IN & BIT5 ){
            if(TA0CCR1 < 4000){
                TA0CCR1 = TA0CCR1 + 200;
            }
        }else{
            if(TA0CCR1 >= 2000){
                TA0CCR1 = TA0CCR1 - 200;
            }
        }
    }

    P1IFG &= ~BIT4;
    P1IE |= BIT4;

}
void ini_uCon(void){

    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    // Configuracoes do BCS
    // MCLK = DCOCLK ~ 16 MHz
    // ACLK = LFXT1CLK = 32768 Hz
    // SMCLK = DCOCLK / 1 ~ 16 MHz
    DCOCTL = CALDCO_16MHZ;
    BCSCTL1 = CALBC1_16MHZ;
    // BCSCTL2 = DIVS0 + DIVS1;
    BCSCTL3 = XCAP0 + XCAP1;

    while(BCSCTL3 & LFXT1OF);
    __enable_interrupt();

}