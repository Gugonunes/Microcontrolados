//Apresente as configurações para o Timer 0 para provocar interrupções periódicas a cada 100 us. Sinais de clock disponíveis: SMCLK = 8 MHz; ACLK = 32768 Hz. Escolha o sinal de clock mais adequado.
TA0CTL = TASSEL1 + MC0;

TA0CCTL0 = CCIE;

TA0CCR0 = 799;