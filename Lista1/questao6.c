//Apresente as configurações para o Timer 0 para provocar interrupções periódicas a cada 30 s. Sinais de clock
//disponíveis: SMCLK = 1 MHz; ACLK = 32768 Hz. Escolha o sinal de clock mais adequado. Considere o uso do modo de contagem up/down do contador.
TA0CTL = TASSEL0 + MC0 + MC1 + ID0 + ID1;

TA0CCTL0 = CCIE;

TA0CCR0 = 61439