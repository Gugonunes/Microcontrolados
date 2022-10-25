void ini_Timer0_debouncer(void){
//CLOCK DE 1MHZ -> SMCLK = 250K
    TA0CTL = TASSEL1;
    TA0CCTL0 = CCIE;
    TA0CCR0 = 6249;
}