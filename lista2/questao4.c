void ini_Timer1_tS1(void){
    TA1CTL = TASSEL1 + ID1;
    TA1CCTL0 = CCIE;
    TA1CCR0 = 62499;
}