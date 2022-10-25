#pragma vector=PORT2_VECTOR
__interrupt void RTI_Porta_2(void){

    P2IE &= ~(BIT3 + BIT4 + BIT5);
    TA0CTL |= MC0;
}