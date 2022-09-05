#include <msp430.h>
unsigned long int i = 0;
void main(void) {

    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer
    //seta tudo como saida
    P1DIR = BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5 + BIT6 + BIT7;
    //todas em baixo nivel
    P1OUT = 0x00;

    //seta tudo como saida
    P2DIR = BIT0 + BIT3 + BIT4 + BIT5 + BIT6 + BIT7;
    //todas em baixo nivel
    P2OUT = BIT1 + BIT2;
    P2REN = BIT1 + BIT2;
    P2IES = BIT1 + BIT2;
    P2IFG = 0;
    P2IE = BIT1 + BIT2;

    while(1){
        P1OUT = BIT0 + BIT5 + BIT6;
        for(i = 0; i < 1600000; i++);  //~ 8s
        P1OUT &= ~BIT0;

        P1OUT ^= BIT1;
        for(i = 0; i < 400000; i++);  //~ 2s
        P1OUT &= ~(BIT1 + BIT5 + BIT6);

        P1OUT = BIT2 + BIT3 + BIT7;   //~ 8s
        for(i = 0; i < 1600000; i++);
        P1OUT &= ~BIT3;

        P1OUT ^= BIT4;
        for(i = 0; i < 400000; i++);  //~ 2s
        P1OUT &= ~(BIT3 + BIT4 + BIT7);
    };

}
//TODO arrumar a interrupçao
#pragma vector = PORT2_VECTOR //interrupção ainda precisa de ajustes
__interrupt void Port2_RTI(void) {
    switch(P1IFG & (BIT1 + BIT2)){
    case BIT1:
        P1IFG &= ~BIT1;
        P1OUT ^= BIT7;
        break;
    case BIT2:
        P1IFG &= ~BIT2;

        break;
    default:
        P1IFG &= ~(BIT1 + BIT2);
        break;
    }
}


