#include "iostm8s105c6.h"
void Init(void)
{
 //Initiall TIM4 and set the setting  
  TIM4_CR1_ARPE = 1; // Allow auto-reload preloa
  TIM4_IER_UIE = 1;     //Allow interrupts
  TIM4_PSCR = 1;     //Prescale 16MHz/1
  TIM4_ARR = 201;    //Auto-reload value(200ms)  
  //TIM4_CR1_CEN = 1;  //TIM4 - start
  
 
 // Initiall legs
  //----------------------------------- Led PIN - PD[0]
  PD_DDR_bit.DDR0 = 1;                  //Output
  PD_CR1_bit.C10 = 1;                   //Push-pull
  PD_CR2_bit.C20 = 1;                   // <10MHz
  //----------------------------------- TRIGGER PIN - PD[2]
  PD_DDR_bit.DDR2 = 1;                  //Output
  PD_CR1_bit.C12 = 1;                   //Push-pull
  PD_CR2_bit.C22 = 1;                   // <10MHz
  //------------------------------------ ECHO PIN - PD[3]
  PD_DDR_bit.DDR3 = 0;                  //Input
  PD_CR1_bit.C13 = 0;                   //Floating input
  PD_CR2_bit.C23 = 0;                   //disallow interrupt
}