#include "STM8_GPIO.h"
/*
#define BeamHigh_Inc TIM2_CCR1L=TIM2_CCR1L+0x01
#define BeamHigh_Dec TIM2_CCR1L=TIM2_CCR1L-0x01

#define BeamLow_Inc TIM2_CCR2L=TIM2_CCR2L+0x01
#define BeamLow_Dec TIM2_CCR2L=TIM2_CCR2L-0x01
TIM4_CR1_CEN = 1;  //TIM4 - start
*/
void Init_TIM(void)
{
 //------------------------------------       Initiall TIM1|2 and set the setting   
  CLK_PCKENR1=0xff;  
 
  TIM2_PSCR = 0x17;     //Prescale 16MHz/1   
  
  TIM2_ARRH = 0x00;
  TIM2_ARRL = 0x81;    //Auto-reload value(200ms)  
  
  TIM2_CCMR2_bit.OC2M=0x6;
  TIM2_CCMR2_bit.OC2PE=1;
  TIM2_CCMR2_bit.CC2S=0x00;
 
  TIM2_CCMR1_bit.OC1M=0x6;
  TIM2_CCMR1_bit.OC1PE=1;
  TIM2_CCMR1_bit.CC1S=0x00;
  
  
  // настройка каналов
  TIM2_CCER1_bit.CC2P=0;
  TIM2_CCER1_bit.CC2E=1;
  
  TIM2_CCER1_bit.CC1P=0;
  TIM2_CCER1_bit.CC1E=1;
 
  //кофициента заполнения  
  TIM2_CCR2H= 0x00;
  TIM2_CCR2L = 0x01;  
  
   //кофициента заполнения  
  TIM2_CCR1H= 0x00;
  TIM2_CCR1L = 0x01;  
  
  //------------------------------------       Initiall TIM4 and set the setting  
  TIM4_CR1_ARPE = 1; // Allow auto-reload preloa
  TIM4_IER_UIE = 1;     //Allow interrupts
  TIM4_PSCR = 1;     //Prescale 16MHz/1
  TIM4_ARR = 201;    //Auto-reload value(200ms)  
  
}

void Init_GPIO(void)
{
  //Valve 1
  PC_DDR_bit.DDR4 = 1;                  //C[4] - output
  PC_CR1_bit.C14 = 1;                   // push-pull mode
  //PC_ODR_bit.ODR7 = 1;                        //ON
  
  //Valve 2
  PC_DDR_bit.DDR5 = 1;                  //C[5] - output
  PC_CR1_bit.C15 = 1;                   // push-pull mode
  
  //Valve 3
  PC_DDR_bit.DDR6 = 1;                  //C[6] - output
  PC_CR1_bit.C16 = 1;                   // push-pull mode
  
  //Relay
  PC_DDR_bit.DDR7 = 1;                  //C[7] - output
  PC_CR1_bit.C17 = 1;                   // push-pull mode
  
  
  
  
}