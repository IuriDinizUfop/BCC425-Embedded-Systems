//**** BCC425 Sistemas Embutidos
//**** DECOM/UFOP - Prof. Eduardo Luz
// Lab1 : Exercitando linguagem C
//
// main.c
// A pr�tica roda em cima da placa TM4C123 (simulador)
// N�o edite este arquivo! Voc� vai editar o Lab1.c
// Baseado no material de aula do Jonathan Valvano - UofTexas

// U0Rx (VCP receive) connected to PA0
// U0Tx (VCP transmit) connected to PA1
#include <stdint.h>
#include "UART.h"
#include "PLL.h"
#include "Lab2.h"

#define True 1
#define False 0
#define Mean 0
#define Monotonic 1
#define COUNT1 5
struct TestCase1{
  uint16_t Readings[50];  // Distances
  uint16_t Average;
  uint32_t Size;
};
typedef const struct TestCase1 TestCase1Type;
TestCase1Type Test1[COUNT1]={
{{276,159,199,297,216,103,188,209,127,19,119,78,16,164,147,48,114,1,114,214,71,87,78,132,68,99,64,173,187,63},
  127,30},
{{224,177,161,0,235,258,159,211,34,30,94,175,277},
  156,13},
{{89,276,80,132,245,221,286,116,40,202,22,155,234,61,26,173,136,292},
	154,18},
{{291,295,112,222,173},
  218,5},
{{93,275,215},
   194,3}
};

#define COUNT2 13
const int16_t Input2[COUNT2] = {-459,-202,-131,-60,11,82,153,224,295,366,437,508,1832};
const int16_t Correct2[COUNT2] = {-273,-130,-91,-51,-12,28,67,107,146,186,225,264,1000};

#define COUNT3 5
struct TestCase3{
  uint16_t Readings[30];  // Array of readings
	uint32_t Size;
	int Correct;    // true if monotonic or not
};
typedef const struct TestCase3 TestCase3Type;
TestCase3Type Test3[COUNT3]={
  { {5,12,12,16,18,22,22,23,24,24,24,26,27,29,32,32,32,34,35,37,38}, 21,True},
  { {36,37,35,34,32,32,32,29,27,26,24,23,22,22,18,16,0,0,0},         19,False},  
  { {69,69,70,70,70,70,70,70,70,70},                                 10,True},
  { {2,4,7,16,27,29,35,29,28,10,9,9,10,13,16,21,24,27,32,32,38},     21,False},
  { {55},                                                            1,True}  
};
extern char Name[];
extern char EID[];
int main(void){ 
  uint32_t n;
  uint16_t result,correct;
  int16_t result2;
  int success=True, fails1=0,fails3=0,fails2=0; 

  PLL_Init(Bus80MHz);
  UART_Init();              // initialize UART
  UART_OutString("\n\rEE319K Spring 2021 Lab 2\n\r");
  UART_OutString("Sensor Data Analysis\n\r");
  UART_OutString(Name); UART_OutString(" EID="); UART_OutString(EID); 
	UART_OutString("\n\rTest of your Average...");
  
  for(n = 0; n < COUNT1 ; n++){
    result = Average(Test1[n].Readings,Test1[n].Size);
		correct = Test1[n].Average;
    if((correct-result<-1)||(correct-result>1)){
			if(fails1<2){
        UART_OutString("\n\rNo, Input is {");
				for(int i=0;i<Test1[n].Size-1;i++){
					UART_OutUDec(Test1[n].Readings[i]);
					UART_OutChar(',');
				}
				UART_OutUDec(Test1[n].Readings[Test1[n].Size-1]);
        UART_OutString("}\n\r Correct Mean= ");
        UART_OutUDec(correct);  
        UART_OutString(" Your Mean= ");
        UART_OutUDec(result);
			}     
			success=False; fails1++;
    }
	}
  if(fails1 == 0){
    UART_OutString("ok\n\r");
  }else{
    UART_OutString("\n\rYour Find_Mean has bugs\n\r"); 
  }       

  UART_OutString("Test of your FtoC...");
  for(n=0; n<COUNT2; n++){
    result2 = FtoC(Input2[n]);
    if((result2-Correct2[n]<-1)||(result2-Correct2[n]>1)){
      if(fails2<3){
        UART_OutString("\n\r No, Input = ");
        UART_OutSDec(Input2[n]);
        UART_OutString("F, Correct Output= ");
        UART_OutSDec(Correct2[n]);  
        UART_OutString("C, Your Output= "); 
        UART_OutSDec(result2);
        UART_OutString("C");
      }
      success=False;fails2++;
    }
  }
  if(fails2 == 0){
    UART_OutString("ok\n\r");
  }else{
    UART_OutString("\n\rYour FtoC has bugs\n\r"); 
  }    
  UART_OutString("Test of your IsMonotonic...");
  for(n = 0; n < COUNT3 ; n++){
    result = IsMonotonic(Test3[n].Readings,Test3[n].Size);
    if(result != Test3[n].Correct){
			if(fails3<2){
        UART_OutString("\n\rNo, Input is {");
				for(int i=0;i<Test3[n].Size-1;i++){
					UART_OutUDec(Test3[n].Readings[i]);
					UART_OutChar(',');
				}
				UART_OutUDec(Test3[n].Readings[Test3[n].Size-1]);
        UART_OutString("}\n\r Correct = ");
        if(Test3[n].Correct){
          UART_OutString("True ");
				}else{
          UART_OutString("False ");
				}
			}
			success=False;
			fails3++;
    }
  }
	if(fails3 == 0){
    UART_OutString("ok\n\r");
  }else{
    UART_OutString("\n\rYour IsMonotonic has bugs\n\r"); 
  }  
  if (success) {
    UART_OutString(" Passed all tests - ");
  }else{
    UART_OutString(" Failed ");
    UART_OutUDec((fails1>0)+(fails3>0)+(fails2>0));
    UART_OutString(" of the 3 parts to this lab.\n\r");
  }
  UART_OutString(" End of Analysis\n\r");
  while(1){
  }
}
