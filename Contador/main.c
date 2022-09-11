#include<msp430.h>
#include<stdio.h>
#define     seg_a       BIT0
#define     seg_b       BIT1
#define     seg_c       BIT2
#define     seg_d       BIT3
#define     seg_e       BIT4
#define     seg_f       BIT5
#define     seg_g       BIT6
#define     seg_p       BIT7

#define     ZERO        (seg_a + seg_b + seg_c + seg_d + seg_e + seg_f)
#define     UM          (seg_b + seg_c)
#define     DOIS        (seg_a + seg_b + seg_g + seg_e + seg_d)
#define     TRES        (seg_a + seg_b + seg_c + seg_d + seg_g)
#define     QUATRO      (seg_b + seg_c + seg_f + seg_g)
#define     CINCO       (seg_a + seg_c + seg_d + seg_g + seg_f)
#define     SEIS        (seg_a + seg_g + seg_c + seg_d + seg_e + seg_f)
#define     SETE        (seg_a + seg_b + seg_c)
#define     OITO        (seg_a + seg_b + seg_c + seg_d + seg_e + seg_f + seg_g)
#define     NOVE        (seg_a + seg_b + seg_c + seg_d + seg_f + seg_g)


unsigned int unidade = 0;
unsigned int dezena = 0;
unsigned int digito = 0;
char sel_disp;

char select_disp(void);
void start_p1(void);
void start_p2(void);
void mostra_digito(char sel_disp);

int main(void){
    WDTCTL = WDTPW | WDTHOLD;
    start_p1();
    start_p2();
    sel_disp = select_disp();
    while(1){
        mostra_digito(sel_disp);
    }
}
char select_disp(void){
    char disp;
    scanf("%c", &disp);
    return disp;
}

void start_p1(void){
    P1DIR = ~(BIT3);
    P1OUT = 0;
    P1IES = BIT3;
    P1IE = BIT3;
    P1IFG = 0;
}

void start_p2(void){
    P2SEL &= ~(BIT6 + BIT7);
    P2DIR = BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5 + BIT6 + BIT7;
    P2OUT = 0;
}

void mostra_digito(char sel_disp){
    if(sel_disp == '1'){
        digito = unidade;
        P1OUT = BIT0;
    }
    else if(sel_disp =='2'){
        digito = dezena;
        P1OUT = BIT1;
    }
    switch(digito){
        case 0:
            P2OUT = ZERO;
            break;
        case 1:
            P2OUT = UM;
            break;
        case 2:
            P2OUT = DOIS;
            break;
        case 3:
            P2OUT = TRES;
            break;
        case 4:
            P2OUT = QUATRO;
            break;
        case 5:
            P2OUT = CINCO;
            break;
        case 6:
            P2OUT = SEIS;
            break;
        case 7:
            P2OUT = SETE;
            break;
        case 8:
            P2OUT = OITO;
            break;
        case 9:
            P2OUT = NOVE;
            break;
        default:
            P2OUT = ZERO;
            break;
    }
}

#pragma vector = PORT1_VECTOR
__interrupt void Port1_RTI(void){
    P1IFG &= ~BIT3;

    if(unidade < 9){
        unidade++;
    }
    else if(dezena < 9){
        unidade = 0;
        dezena++;
    }
    else{
        unidade = 0;
        dezena = 0;
    }
}
