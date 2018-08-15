#include "iostm8s105c6.h"
//#include "iostm8l152c6.h"

//#include "iostm8s003f3.h"

/*--------------================----------------------==================-----------------------
This program for NightLed. This device be On BIG Light(2 second press), Low Light(1 short press), MixingColorMode(5 second press).
Have 1 botton and 3 output.
PC[4,5] - Output LED {Big and Low light}
PC[3] - button
PC[6] - button for Mixed Led
PD[4,5,6] - Ouput LED {Mixed Color}

=============----------------=======================------------------=======================*/
//delay
void Delay(int Count)
{
  for(unsigned long delay_count = 0; delay_count < Count; delay_count++);
}

int main( void )
{
  int CountButton = 0;
  int OutOnCycle = 0;
  //--------------------------------------------   Button for Big\Low led  D
  PC_DDR_bit.DDR3 = 0;                          //PC[3] - input
  PC_CR1_bit.C13 = 0;                           //floating input
 // PA_CR2_bit.C21 = 0;                           //disallow interrupt
  //--------------------------------------------------------   Low Led
  PC_DDR_bit.DDR4 = 1;                  //PC[4] - output
  PC_CR1_bit.C14 = 1;                   // push-pull mode
  //--------------------------------------------------------  Big Led
  PC_DDR_bit.DDR5 = 1;                  //PC[5] - output
  PC_CR1_bit.C15 = 1;                   // push-pull mode  
 //-------------------------------------------------------  Button for Mixed LED
  PC_DDR_bit.DDR6 = 0;                  //PC[6] - input
  PC_CR1_bit.C16 = 0;                   //floating input
  //------------------------------------------------------ Mixed Led
                          //Red
  PD_DDR_bit.DDR4 = 1;                  //PD[4] - output
  PD_CR1_bit.C14 = 1;                   // push-pull mode
                          //Blue
  PD_DDR_bit.DDR5 = 1;                  //PD[5] - output
  PD_CR1_bit.C15 = 1;                   // push-pull mode
                          //Green
  PD_DDR_bit.DDR6 = 1;                  //PD[6] - output
  PD_CR1_bit.C16 = 1;                   // push-pull mode
  //-------------------------------------------------------
  
  while(1)
  {
    //Led button
    if(PC_IDR_bit.IDR3 == 0)
    {
      CountButton = 1;
      Delay(5000);
    if(PC_IDR_bit.IDR3 == 0)
      {
        CountButton = 2;
        Delay(10000);      
      }
    }
    //Mixed botton
    if(PC_IDR_bit.IDR6 == 0)
    {
      CountButton = 3;
      Delay(5000);
    if(PC_IDR_bit.IDR6 == 0)
      {
       CountButton = 4;
       Delay(10000);      
      }
    }
    
    if(CountButton == 1)  //Low delay button -> On migl Light
    {           
      PC_ODR_bit.ODR4 = 1;
      PC_ODR_bit.ODR5 = 0;
      CountButton = 0;
      Delay(20000);
    }
    
    if(CountButton == 2)  //Midl delay button -> on Big Light
    {      
      PC_ODR_bit.ODR5 = 1;
      PC_ODR_bit.ODR4 = 0;
      CountButton = 0;
      Delay(30000);
    }
    if(CountButton == 3)  //Low delay for Mixed button -> Off All
    {  
      //OFF ALL
      PC_ODR_bit.ODR4 = 0;
      PC_ODR_bit.ODR5 = 0;
      PD_ODR_bit.ODR4 = 0;
      PD_ODR_bit.ODR5 = 0;
      PD_ODR_bit.ODR6 = 0;
      CountButton = 0;
      Delay(30000);
    }
    if(CountButton == 4)  //Midl delay for Mixed button -> MixedLight
    {  
      OutOnCycle = 1;
      
     while(OutOnCycle)
     {
      PD_ODR_bit.ODR4 = 1;
      Delay(10000);
      PD_ODR_bit.ODR5 = 1;
      Delay(10000);
      PD_ODR_bit.ODR6 = 1;
      Delay(10000);
      
      if(PC_IDR_bit.IDR6 == 0)
    {
      OutOnCycle = 0;
    }
    
      PD_ODR_bit.ODR4 = 0;
      Delay(10000);
      PD_ODR_bit.ODR6 = 0;
      Delay(10000);
      PD_ODR_bit.ODR5 = 0;
      
      
      if(PC_IDR_bit.IDR6 == 0)
    {
      OutOnCycle = 0;
    }
    
      PD_ODR_bit.ODR6 = 1;
      Delay(10000);
      PD_ODR_bit.ODR5 = 1;
      Delay(10000);
      PD_ODR_bit.ODR4 = 1;
      Delay(10000);
        
      if(PC_IDR_bit.IDR6 == 0)
    {
      OutOnCycle = 0;
    }
    
      PD_ODR_bit.ODR5 = 0;
      Delay(10000);
      PD_ODR_bit.ODR4 = 0;
      Delay(10000);
      PD_ODR_bit.ODR6 = 0;
      
      
      
      if(PC_IDR_bit.IDR6 == 0)
    {
      OutOnCycle = 0;
    }
     }
      
       CountButton = 0;
        Delay(30000);
    } 
   // if(PC_IDR_bit.IDR2 == 1)
   // {
  //     PC_ODR_bit.ODR7 = 1;
  //  }
  }
  return 0;
}
