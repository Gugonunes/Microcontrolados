#pragma vector=TIMER0_A0_VECTOR
__interrupt void RTI_Modulo_0_Timer_0(void){

    TA0CTL &= ~MC0;

    switch( P2IFG & (BIT3 + BIT4 + BIT5) ){
        case BIT3:
            P2IFG &= ~BIT3;
            if(P2IN & BIT3){
                
                modo = 0;
            }
            break;
        case BIT4:
            P2IFG &= ~BIT4;
            if(P2IN & BIT4){
                
                modo = 1;
            }
            break;

        case BIT5:
            P2IFG &= ~BIT5;
            if(P2IN & BIT5){
                
                modo = 2;
            }
            break;

        default:    // Em caso de falha na leitura de S2
            P2IFG &= ~(BIT3 + BIT4 + BIT5);
            modo = 0;  // modo DESLIGADO
            break;
    }
    P2IE |= BIT3 + BIT4 + BIT5;

    set_modo(modo);
}