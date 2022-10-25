void set_modo(unsigned char mode){

    switch(mode){
    case 0: // modo DESLIGADO
        // DESLIGA Lamp., desabilita int. de P1.4, Timer1 parado
        P2OUT &= ~BIT7;
        P1IE &= ~BIT4;
        TA1CTL &= ~MC0;
        break;
    case 1: // modo S_LIGADO
        P2OUT |= BIT7;
        P1IE &= ~BIT4;
        TA1CTL &= ~MC0;
        break;
    case 2:
        P2OUT &= ~BIT7;

        P1IFG &= ~BIT4;
        P1IE |= BIT4;
        TA1CTL |= MC0;
        tempo = 0;
        break;
    }
}