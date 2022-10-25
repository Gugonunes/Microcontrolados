#pragma vector=TIMER1_A0_VECTOR
__interrupt void RTI_Modulo_0_Timer_1(void){

    if(tempo>=tS1){
        tempo = 0;
        P2OUT &= ~BIT7;
        TA1CTL &= ~MC0;
    }else{
       tempo++;
    }
}