#include "Initialization_periphery.h"

/* WaterGND  PD[2]
*  WaterBack PD[3]
*  Light     PD[4]
*  LightCool PD[5]
*  DayBotton PC[4]
*/
int count = 0;
int second = 0;
int hour = 0;
int minutes = 0;

void TIM_Hour();
void TIM_Min();

// 24 hour and 60 sec timer
//=================================================     Interrupts vector TIM1
#pragma vector = TIM4_OVR_UIF_vector
__interrupt void TIM4_OVE_UIF_handler(void)
{  
  if(TIM4_SR_UIF == 1)
  {
    TIM4_SR_UIF = 0;   //Interrupts flag - disallow    
    count++;    
   
   if(count >= 400) //Count for 5ms (5ms*200)=1sec
    {     
      count = 0;     
      second++;      
    }
    
    if(second >= 60) 
   {
     second = 0;
     TIM_Min();      
   }        
  }    
}



void InitPeriph()
{
  //-------------------0----------------- Day/Night botton - PC[3]
  PC_DDR_bit.DDR3 = 0;                          //PC[3] - input
  PC_CR1_bit.C13 = 1;                           //push-pull input
  PC_CR1_bit.C13 = 0;                           //disallow interrupt
 
  
  //-------------------0----------------- Led PIN - PD[2]
  PD_DDR_bit.DDR2 = 1;                  //Output
  PD_CR1_bit.C12 = 1;                   //Push-pull
  PD_CR2_bit.C22 = 1;                   // <10MHz
  
  //-------------------0----------------- Led PIN - PD[3]
  PD_DDR_bit.DDR3 = 1;                  //Output
  PD_CR1_bit.C13 = 1;                   //Push-pull
  PD_CR2_bit.C23 = 1;                   // <10MHz
  
  //-------------------0----------------- Led PIN - PD[4]
  PD_DDR_bit.DDR4 = 1;                  //Output
  PD_CR1_bit.C14 = 1;                   //Push-pull
  PD_CR2_bit.C24 = 1;                   // <10MHz
  
  //-------------------0----------------- Led PIN - PD[5]
  PD_DDR_bit.DDR5 = 1;                  //Output
  PD_CR1_bit.C15 = 1;                   //Push-pull
  PD_CR2_bit.C25 = 1;                   // <10MHz  
 
   //------------------------------------       Initiall TIM4 and set the setting    
  TIM4_CR1_ARPE = 1; // Allow auto-reload preloa
  TIM4_IER_UIE = 1;     //Allow interrupts
  TIM4_PSCR = 5;     //Prescale 
  TIM4_ARR = 155;    //Auto-reload value(30Hz)  
  TIM4_CR1_CEN = 1;  //TIM4 - start
  
  asm("rim");
}
   
//Hour ++ function
void TIM_Hour()
{
  if(hour >= 24)
  {
    hour = 0;
  }
  hour ++;
}

//Minutes ++ function
void TIM_Min()
{
  if(minutes >= 60)
  {
    minutes = 0;
    TIM_Hour();
  }
  minutes ++;
}

// 0 - second, 1 - minutes, 2 - hour
int TIM_GetTime(int SecMinHour)
{
  switch(SecMinHour)
  {
  case 0:
    return second;
    break;
    
  case 1:
     return minutes;
     break;

  case 2:
     return hour;
     break;  
  }
  
  return 0;
}

// Set Second
void TIM_Second_Set(int Value)
{
  second = Value;
}

// Set Minute
void TIM_Minute_Set(int Value)
{
  minutes = Value;
}

// Set Hour
void TIM_Hour_Set(int Value)
{
  hour = Value;
}
