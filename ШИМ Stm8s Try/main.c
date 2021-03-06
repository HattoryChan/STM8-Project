//#include "iostm8s105c6.h"
#include "iostm8s003f3.h"
//#include "iostm8l152C6.h"

__interrupt void TIM1_OVR_UIF_hundler(void);
void init(void)
{
  PC_DDR_bit.DDR2 = 1;                  //Input
  PC_CR1_bit.C12 = 1;                  //Push-pull
  PC_CR2_bit.C22 = 1;                   // <10MHz
  
  //TIM1 setting
  TIM1_CR2 = 0;         //Timing @master@ with periphery
  TIM1_SMCR = 0;        //Timing @slave@ with perephery
  TIM1_ETR = 0;         //Output timing - OFF
  TIM1_IER = MASK_TIM1_IER_UIE;         //Interrupts - allow
  //First set PSCRH!!!!
  TIM1_PSCRH = 0;
  TIM1_PSCRL = 0;                      //30 - 1sec  0 - 10ms
  
  TIM1_ARRH = 0;                     //Freq byte
  TIM1_ARRL = 0x0b;                     //Freq byte
  
  TIM1_CCR1H = 0xFF;                    //dyty cycle
  TIM1_CCR1L = 0;                    //duty cycle
  
  TIM1_CCER1_CC1P = 0;
  TIM1_CCER1_CC1E = 1;
  
  TIM1_CCMR1_OC1M = 1;
  
  TIM1_CR1 =  MASK_TIM1_CR1_URS;      //Endless accounts Mode
  TIM1_CR1 =  MASK_TIM1_CR1_CEN;        //Start Tim1
}
int main( void )
{
  init();
  asm("rim");   //Interrupts allow   
 
  
  while(1)
  {
    asm("nop");
  }  
}

//Interrupts vector TIM1
#pragma vector = TIM1_OVR_UIF_vector
__interrupt void TIM1_OVE_UIF_handler(void)
{
  if(TIM1_SR1_UIF==1)    //Check called interrupts function
  {
    TIM1_SR1_UIF = 0;   //Interrupts flag disallow
    PC_ODR_bit.ODR2 ^= 1; //LEG PD0 ON\Off
  }
} 