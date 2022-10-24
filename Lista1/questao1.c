//Apresente as configurações para o Timer 0 para provocar interrupções periódicas a cada 5 ms. Considere o uso do clock: SMCLK = 2 MHz.
TA0CTL = TASSEL1 + MC0 ;
TA0CCTL0 = CCIE;
TA0CCR0 = 9999;