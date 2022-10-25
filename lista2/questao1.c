void ini_uCon(void){

    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    DCOCTL = CALDCO_1MHZ;
    BCSCTL1 = CALBC1_1MHZ;
    BCSCTL2 = DIVS1;
    BCSCTL3 = XCAP0 + XCAP1;

    WHILE(BCSCTL3 & LFXT1OF);

     __enable_interrupt();

}