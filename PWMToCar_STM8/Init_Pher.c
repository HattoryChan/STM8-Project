#include "Init_Pher.h"
//TIM2 CH1 - High beam, CH2 - Low beam  
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
}
