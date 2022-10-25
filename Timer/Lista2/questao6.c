void read_tS1(void){

       switch(~P2IN & (BIT0 + BIT1 + BIT2){

               case (BIT0 + BIT1 + BIT2):

                   tS1 = 120;

                   break;

               case (BIT0 + BIT1):

                   tS1 = 60;

                   break;

               case (BIT0 + BIT2):

                   tS1 = 50;

                   break;

               case (BIT0):

                   tS1 = 40;

                   break;

               case (BIT1 + BIT2):

                   tS1 = 30;

                   break;

               case (BIT1):

                   tS1 = 20;

                   break;

               case (BIT2):

                   tS1 = 10;

                   break;

               case (0):

                   tS1 = 5;

                   break;

               default:
                   tS1 = 0;

                   break;

       }

}