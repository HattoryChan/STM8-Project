#include "iostm8s003f3.h"

#define Led_First PD_ODR_bit.ODR4
#define Led_Second PD_ODR_bit.ODR5
#define Relay_First PC_ODR_bit.ODR3
#define Relay_First_Blink PC_ODR_bit.ODR3^=1
#define Relay_Second PC_ODR_bit.ODR4
#define Relay_Second_Blink PC_ODR_bit.ODR4^=1
#define Button_Setting PC_IDR_bit.IDR5

/*==========-----------===========-------------============-----------========
This program will be getted two range value from HCSR04 and control two relay
 this value. Two leds help us to indiction
----------==========------------==============-----------===========---------*/

int TimeCount(void);
void Init(void);
int Ranging(void);

int UserFirstRangeMAX = 0;
int UserFirstRangeMIN = 0;
int UserSecondRangeMAX = 0;
int UserSecondRangeMIN = 0;
int UserRange;

//================================================    Delay
void Delay(int Count)
{
  for(unsigned long delay_count = 0; delay_count < Count; delay_count++);
}


int main( void )
{    
  Init();
 //------------ Set UserFirstRange Value
  Led_First = 1;
  while(!(Ranging() <= 500 && Button_Setting == 0))
    {
      Delay(1000);
    }
      Delay(1000);
    UserFirstRangeMAX = Ranging()+2;
   UserFirstRangeMIN = UserFirstRangeMAX-4;  
  Led_First = 0;
    Delay(1000);
  //----------- Set UserSecondRange Value
  Led_Second = 1;
  while(Button_Setting == 0);
  
  while(!(Ranging() <=900 && Button_Setting == 0))
  {
    Delay(1000);
  }
      Delay(1000);
    UserSecondRangeMAX = Ranging()+2;
    UserSecondRangeMIN = UserSecondRangeMAX-4;  
  Led_Second = 0;
  while(Button_Setting == 0);
    Delay(1000);
  //-----------  ENdless CYCLE
  while(1)
  {
     UserRange = Ranging();              //Get userRange    
   //------- Check First Value    
    if(UserRange <= UserFirstRangeMAX && UserRange >= UserFirstRangeMIN)
    {      
      Relay_First_Blink;
      Delay(10000);
    }
    //------ Check second Value
    if(UserRange <= UserSecondRangeMAX && UserRange >= UserSecondRangeMIN)
    {     
      Relay_Second_Blink;
      Delay(10000);
    }
    Delay(500);    
  }
}
