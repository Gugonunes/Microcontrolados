#include <msp430.h> 
unsigned long int i = 0;
void main(void) {

    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer
    __enable_interrupt();
    //seta tudo como saida e bit0 +bit1 como entrada (botões)
    P1DIR = ~(BIT0 + BIT1);
    P1OUT = BIT0 + BIT1;
    P1REN = BIT0 + BIT1;
    P1IES = BIT0 + BIT1;
    P1IFG = 0;
    P1IE = BIT0 + BIT1;

    //seta tudo como sa�da
    P2DIR = BIT0 + BIT1 + BIT2 +BIT3 + BIT4 + BIT5 + BIT6 + BIT7;
    //todas em baixo n�vel
    P2OUT = 0x00;
    P2IFG = 0;

    while(1){
        P1OUT = BIT5 + BIT6;
        P2OUT = BIT1;
        for(i = 0; i < 800000; i++);  //~ 8s
        P2OUT &= ~BIT1;

        P2OUT ^= BIT2;
        for(i = 0; i < 200000; i++);  //~ 2s
        P1OUT &= ~(BIT5 + BIT6);
        P2OUT &= ~BIT2;

        P1OUT = BIT2 + BIT3 + BIT7;   //~ 8s
        for(i = 0; i < 800000; i++);
        P1OUT &= ~BIT3;

        P1OUT ^= BIT4;
        for(i = 0; i < 200000; i++);  //~ 2s
        P1OUT &= ~(BIT3 + BIT4 + BIT7);
    };

}

#pragma vector = PORT1_VECTOR
__interrupt void Port1_RTI(void) {
    switch(P1IFG & (BIT0 + BIT1)){
    case BIT0:
        P1IFG &= ~BIT0;

        if((P2OUT == BIT1) && (P1OUT == BIT5 + BIT6)){
            P1OUT ^= BIT2 + BIT6;
            P2OUT ^= BIT1;
            for(i = 0; i < 400000; i++);  //~ 4s
            P1OUT ^= BIT2 + BIT6;
            P2OUT ^= BIT1;
        }

        break;
    case BIT1:
        P1IFG &= ~BIT1;

        if(P1OUT == BIT2 + BIT3 + BIT7){
            P1OUT ^= BIT3 + BIT5 + BIT7;
            for(i = 0; i < 400000; i++);  //~ 4s
            P1OUT ^= BIT3 + BIT5 + BIT7;
        }

        break;
    default:
        P1IFG &= ~(BIT0 + BIT1);
        break;
    }
}


