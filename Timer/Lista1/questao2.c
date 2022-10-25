//Apresente as configurações para o Timer 0 para provocar interrupções periódicas a cada 250 ms. Considere o uso do clock: SMCLK = 2 MHz.
TA0CTL = TASSEL1 + MC0 + ID0+ID1;
TA0CCTL = CCIE;
TA0CCR0 = 62499;