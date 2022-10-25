#pragma vector=PORT1_VECTOR
__interrupt void RTI_Porta_1(void){
     

    P1IFG = 0;
    P1IE &= ~BIT4;

    if(P1IN & BIT4){
        read_tS1();  // Leitura de t(S1)
        tempo = 0; // Zera variável global de temporizacao
        P2OUT |= BIT7; // Liga Lamp.
        TA1CTL |= MC0; // Inicia temporizador de t(S1)
    }
}