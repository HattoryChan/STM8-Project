#include "iostm8s105c6.h"

/*===============------------------------==================----------------
This Program will be get impulse from HC SR-04, 
     and remodel this impulse to range.
TIM4 - Not needed this :(
=======----------------------=============------------------===============*/

#define Trig_Pin PD_ODR_bit.ODR2
#define Echo_Pin PD_IDR_bit.IDR3
#define Led_Pin PD_ODR_bit.ODR0
#define TIM4_Start TIM4_CR1_CEN = 1
#define TIM4_Stop TIM4_CR1_CEN = 0
#define Led_Pin_Blink PD_ODR_bit.ODR0^=MASK_PD_ODR_ODR0

__interrupt void TIM4_OVE_UIF_handler(void);
void Init(void);                //Init port and periphery
int TimeCount(void);            //Find Time signal
void Ranging(void);             //Calculate range

unsigned int msecond = 0;
unsigned int milesecond = 0;
unsigned int second = 0;
int range = 0;

//================================================    Delay
void Delay(int Count)
{
  for(unsigned long delay_count = 0; delay_count < Count; delay_count++);
}

int main( void )
{
  Init();
  // Allow global Interrupts
  asm("rim");      
  while(1)
  {    
    Ranging();
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
      }
    }  
  }    
}
//=======================================================       Range calculate
void Ranging(void)
{  
  range = TimeCount()/12;                       //Calculate to sentimeters
  if(range <= 20)
   {
    Led_Pin_Blink; //LEG PD0 ON\Off  
      Delay(30000);
    Led_Pin_Blink; //LEG PD0 ON\Off  
   }  
      Delay(1000);
}
//===================================================      Impulse Echo pin time
int TimeCount(void)
{  
  int time = 0;
  
      Trig_Pin = 1;          //TRIG PIN - Start pulse
   for(int i = 30; i >= 0; i--);
      Trig_Pin = 0;         //TRIG PIN - Off pulse
  while(Echo_Pin==0);        //Wait impulse
  while(Echo_Pin==1)         //Counted impulse time
    {
      time++;
    }
  
  return time;
}