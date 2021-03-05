//**** BCC425 Sistemas Embutidos
//**** DECOM/UFOP - Prof. Eduardo Luz
// Lab3 : Mapa de Memória do ARM
//
// main.c
// A prรกtica roda em cima da placa TM4C123 (simulador)
// Baseado no material de aula do Jonathan Valvano - UofTexas

// U0Rx (VCP receive) connected to PA0
// U0Tx (VCP transmit) connected to PA1
#include <stdint.h>

#define SYSCTL_RCGCGPIO_R       (*((volatile uint32_t *)0x400FE608)) // aponta para o registrador de clock 
#define GPIO_PORTF_CR 					(*((volatile uint32_t *)0x40025524)) // aponta parar o registrador commit register 
#define GPIO_PORTF_LOCK 				(*((volatile uint32_t *)0x40025520)) // aponta parar o registrador lock
#define GPIO_PORTF_PUR_R 				(*((volatile uint32_t *)0x40025510)) // aponta para o registrador de Pull-Down
#define	GPIO_PORTF_DATA					(*((volatile uint32_t *)0x400253FC)) // aponta para o registrador DATA // 0x3FC Offset
#define	GPIO_PORTF_DIR					(*((volatile uint32_t *)0x40025400)) // aponta para o registrador DIR 
#define	GPIO_PORTF_DEN					(*((volatile uint32_t *)0x4002551C)) // aponta para o registrador DEN
#define	GPIO_PORTF_AMSEL				(*((volatile uint32_t *)0x40025528)) // aponta para o registrador AMSEL
#define	GPIO_PORTF_AFSEL				(*((volatile uint32_t *)0x40025420)) // aponta para o registrador AFSEL 
#define GPIO_PORTF_PCTL         (*((volatile uint32_t *)0x4002552C)) // aponta parar o registrador PCTL 
#define MASK(x) 								(1UL << (x))

int main(void){ 
    /* 

    ALUNOS :
    RAPHAEL IANNINI DUTRA DOS SANTOS
    IURI DA SILVA DINIZ

    */

// INICIO
		SYSCTL_RCGCGPIO_R |= 0x00000020;        // enable clock Port F (0010 0000)
    GPIO_PORTF_LOCK = 0x4C4F434B; 					// unlock CR
		GPIO_PORTF_CR = 0x1F; 									// set CR for output pins (0001 1111)
		GPIO_PORTF_PUR_R = 0x11; 								// define Port F4 and F0 as pull-up  (0001 0001)
		GPIO_PORTF_DIR = 0x0E; 									// define Port F2 and F3 as output and F4 as input (0000 1110) 
		GPIO_PORTF_AMSEL = 0x00;								// disable the analog function for Port F (0000 0000)
		GPIO_PORTF_AFSEL = 0x00;
		GPIO_PORTF_DEN = 0x1F; 									// define Port F2,F3 and F4 as digital pins (0001 1111)
	  GPIO_PORTF_PCTL = 0x00000000;			
		
		while(1)
		{
				if(GPIO_PORTF_DATA & MASK(4))
				{
						GPIO_PORTF_DATA &= ~ (MASK(2)|MASK(3)); 
				} else GPIO_PORTF_DATA |= (MASK(2)|MASK(3));
				
				if(GPIO_PORTF_DATA & MASK(0))
				{
						GPIO_PORTF_DATA &= ~MASK(1); 
				} else GPIO_PORTF_DATA |= MASK(1);				
		}		

/*	
		while(1){

			if((GPIO_PORTF_DATA & MASK(4)) && (GPIO_PORTF_DATA & MASK(0)) ) // Todas as chaves desligadas:
				{
						GPIO_PORTF_DATA &= 0x00000000; // Desliga todos os LEDs
					} else if (!(GPIO_PORTF_DATA & MASK(4)) && (GPIO_PORTF_DATA & MASK(0)) ) // Apenas SW1 ligada:
				{
						GPIO_PORTF_DATA = (MASK(2) | MASK(3)); // Ativa LEDs 2 e 3
					} else if ((GPIO_PORTF_DATA & MASK(4)) && !(GPIO_PORTF_DATA & MASK(0)) ) //  Apenas SW2 ligada:
				{
						GPIO_PORTF_DATA |= (MASK(1)); // Ativa LED 1
					} else // Ambas as chaves ligadas:
							{
									GPIO_PORTF_DATA = (MASK(1) | MASK(2) | MASK(3)); // Ativa todos os LEDs
							}
		}
*/
}
