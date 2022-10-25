//Apresente as configurações para o Timer 0 para provocar interrupções periódicas a cada 125 ms. Sinais de clock disponíveis: SMCLK = 4 MHz; ACLK = 32768 Hz. Escolha o sinal de clock mais adequado.
TA0CTL = TASSEL1 + MC0 + ID0 + ID1;

TA0CCTL0 = CCIE;

TA0CCR0 = 62499