//#include "iostm8s105c6.h"
#include "iostm8s003f3.h"

unsigned int msecond = 0;
unsigned int milesecond = 0;
unsigned int second = 0;

__interrupt void TIM4_OVE_UIF_handler(void);

void Init(void)
{
 //------------------------------------       Initiall TIM4 and set the setting  
  TIM4_CR1_ARPE = 1; // Allow auto-reload preloa
  TIM4_IER_UIE = 1;     //Allow interrupts
  TIM4_PSCR = 1;     //Prescale 16MHz/1
  TIM4_ARR = 201;    //Auto-reload value(200ms)  
  TIM4_CR1_CEN = 1;  //TIM4 - start
  
 //-------------------0----------------- Led PIN - PD[2]
  PD_DDR_bit.DDR2 = 1;                  //Output
  PD_CR1_bit.C12 = 1;                   //Push-pull
  PD_CR2_bit.C22 = 1;                   // <10MHz
}

int main( void )
{
  Init();
  // Allow global Interrupts
  asm("rim");     
  while(1)
  {  
    
  }
}

//=================================================     Interrupts vector TIM4
#pragma vector = TIM4_OVR_UIF_vector
__interrupt void TIM4_OVE_UIF_handler(void)
{  
  if(TIM4_SR_UIF == 1)
  {
    TIM4_SR_UIF = 0;   //Interrupts flag - disallow    
    msecond++;
    if(msecond >= 5)
    {
    msecond = 0;
    milesecond++;
    if(milesecond >=1000)
      {
        milesecond = 0;
        second++;      
     PD_ODR_bit.ODR2^=1;              //     ON|OFF LED
      }
    }  
  }    
}