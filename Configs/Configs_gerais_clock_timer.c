//*****CLOCK*****

DCOCTL = CALDCO_[FREQ]
BCSCTL1 = CALBC1_[FREQ]
BCSCTL2 = DIVS0 + DIVS1;
BCSCTL3 = XCAP0 + XCAP1;

//OPÇÕES DE CLOCK:
MCLK = DCOCLK ~16MHZ
SMCLK = DCOCLK / 8 ~2MHZ 
ACLK = LFXT1CLK = 32.768 Hz


//*****TIMER******
//setando para exemplo da aula, com ACLK em UP mode
TA0CTL = TASSEL0 + MC0;
TA0CCTL0 = CCIE;
TA0CCR0 = 32767; //Esse vem do cálculo

#pragma vector=TIMER0_A0_VETOR
__interrupt void TA0CCR0_RTI(void){
	//Faz o que quer fazer com o timer, por exemplo mudar o estado de um led:
	P1OUT ^= BIT0; 
}


//*****DEBOUNCER*****
