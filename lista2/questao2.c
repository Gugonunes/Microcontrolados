void ini_P1_P2(void){
    P1DIR = ~(BIT4);
    P1REN = 0;
    P1OUT = 0;
    P1IES = 0;
    P1IFG = 0;
    P1IE = BIT4;

    P2SEL &= ~BIT7;
    P2DIR = ~(BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5);
    P2REN = BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5;
    P2OUT = BIT0 + BIT1 + BIT2;

    P2IES = 0;
    P2IFG = 0;
    P2IE = BIT3 + BIT4 + BIT5;
}