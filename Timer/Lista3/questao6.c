P2SEL2 &= ~(BIT6 + BIT7)

P2DIR = BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5 + BIT6 + BIT7;

P2OUT = 0;

P2IFG = 0;

P2SEL |= BIT1 + BIT4;