#include <msp430.h>
unsigned long int i = 0;
unsigned char ENCODER;
void main (void){
    WDTCTL = WDTPW | WDTHOLD;
    P1DIR = ~(BIT1 + BIT2 + BIT3 + BIT4);
    P1OUT = BIT1 + BIT2 + BIT3 + BIT4;
    P1REN = BIT1 + BIT2 + BIT3 + BIT4;

    P2SEL &= ~(BIT6 + BIT7);
    P2SEL2 &= ~(BIT6 + BIT7);
    P2DIR = BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5 + BIT6 + BIT7;
    P2OUT = BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5 + BIT6 + BIT7;

    while(1){
        ENCODER = (P1IN & (BIT1 + BIT2 + BIT3 + BIT4))/2; //precisamos dividir por 2, pois o bit 0 nao é o primeiro
        if(ENCODER <=1){
            P2OUT = BIT0;
        }
        else if(ENCODER > 1 && ENCODER <=4){
            P2OUT = BIT0 + BIT1;
        }
        else if(ENCODER > 4 && ENCODER <=9){
            P2OUT = BIT0 + BIT1 + BIT2;
        }
        else if(ENCODER > 9 && ENCODER <=12){
            P2OUT = BIT0 + BIT1 + BIT2 + BIT3;
        }
        else if(ENCODER >12 && ENCODER <=15){
            P2OUT = BIT0 + BIT1 + BIT2 + BIT3 + BIT4;
        }
    }
}
