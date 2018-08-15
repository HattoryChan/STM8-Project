/*   This program control aeroponic system:
*      Control timing relay module ON|OFF(0|1):
*        Light, WaterGND, WaterBack, LightCool
*    Day/Hight botton - if press, reset MC to day start
*                       or night start
*/

/*  WaterGND[0,1][ON,OFF]   every 15 minutes for 7 secinds  PD[2]
*   WaterBack[0,1][ON,OFF]  every WaterGND time +1 sec in start and end time PD[3]
*   Light[0,1][ON,OFF]      every 12hour light\dark PD[4]
*   LightCool[0,1][ON,OFF]  every Light time PD[5]
*   DayBotton[1,11][Day,Night] if we do short press - night
*/

#include "Initialization_periphery.h"

#define WaterGND_ON PD_ODR_bit.ODR2 = 0
#define WaterGND_OFF PD_ODR_bit.ODR2 = 1

#define WaterBack_ON PD_ODR_bit.ODR3 = 0
#define WaterBack_OFF PD_ODR_bit.ODR3 = 1

#define Light_ON PD_ODR_bit.ODR4 = 0
#define Light_OFF PD_ODR_bit.ODR4 = 1

#define LightCool_ON PD_ODR_bit.ODR5 = 0
#define LightCool_OFF PD_ODR_bit.ODR5 = 1

int g_Remember_Sec = 0;
int g_WaterGND_Sec = 0;  
int g_Watering_Flag = 0; //In this part time was watering flag

struct Relay
{
   int Status;
   int TimeWork; //need show units
   int TimeDelay; //need show units
};


int main( void )
{
  InitPeriph();   
  
  struct Relay WaterGND;
  WaterGND.TimeWork = 7; //second
  WaterGND.TimeDelay = 15; //minute
  WaterGND.Status = 0; //OFF
  
  // ON | OFF every WaterGND + 1 sec
  struct Relay WaterBack;
  WaterBack.TimeWork = 12; //second
  WaterBack.TimeDelay = 15; //minute
  WaterBack.Status = 0;
  
  struct Relay Light;
  Light.TimeWork = 12; //hour
  Light.TimeDelay = 12; //hour
  Light.Status = 0;
 
  //ON |OFF every Light Time
  struct Relay LightCool; 
  LightCool.TimeWork = 12; //hour
  LightCool.TimeDelay = 12; //hour
  LightCool.Status = 0;
  //OFF all relay
   WaterGND_OFF;
   WaterBack_OFF;
   Light_OFF;
   LightCool_OFF;
   
  while(1)
  {
   
   //Light LightCool relay start check
    if(TIM_GetTime(2) < 12 && Light.Status == 0 && LightCool.Status == 0) 
    {
      Light_ON;
      LightCool_ON;
      LightCool.Status = 1;
      Light.Status = 1;
    }
    //Light and LightCool end check
    if(TIM_GetTime(2) >= 12 && Light.Status == 1 && LightCool.Status == 1) 
    {
      Light_OFF;
      LightCool_OFF;
      LightCool.Status = 0;
      Light.Status = 0;
   }   
    
    //WaterGND and WaterBack relay start/end check
    if(TIM_GetTime(1) == 0 || TIM_GetTime(1) == 15 || TIM_GetTime(1) == 30 || TIM_GetTime(1) == 45)
    {
      //start
      if(WaterGND.Status == 0 && g_Watering_Flag == 0)
      {
        WaterGND_ON;
        WaterGND.Status = 1;        
        g_WaterGND_Sec = TIM_GetTime(0);        
      }
      if(WaterBack.Status == 0 && g_Watering_Flag == 0 && g_WaterGND_Sec < TIM_GetTime(0))
      {
        WaterBack_ON;
        WaterBack.Status = 1;
        g_Watering_Flag = 1;
      }
      //end
      if(WaterGND.Status == 1 && ((g_WaterGND_Sec + WaterGND.TimeWork) < TIM_GetTime(0)))
      {
        WaterGND_OFF;
        WaterGND.Status = 0;
      }
      if(WaterBack.Status == 1 && ((g_WaterGND_Sec + WaterBack.TimeWork + 1) < TIM_GetTime(0)))
      {
        WaterBack_OFF;
        WaterBack.Status = 0;
      }
    }  
    //In this part time was watering flag reset
    if(TIM_GetTime(1) == 1 || TIM_GetTime(1) == 16 || TIM_GetTime(1) == 31 || TIM_GetTime(1) == 46)
    {
      g_Watering_Flag = 0;
    }
    /*
    //Day/Night botton part, short press - night
     if(PC_IDR_bit.IDR3 == 1)
    {
      g_Remember_Sec = TIM_GetTime(0);    
     //Short press - night    
       TIM_Second_Set(0);
       TIM_Minute_Set(0);
       TIM_Hour_Set(12);      
    }      
    */
   }    
}




