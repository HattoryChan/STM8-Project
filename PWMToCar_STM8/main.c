/*  "разжигаем" Low и High, затем Low остается гореть
*    а High Тушится
*
*/

#include "main.h"

#define BeamLow_TIM_Start TIM2_CR1_CEN = 1
#define BeamLow_TIM_Stop  TIM2_CR1_CEN = 0

#define BeamHigh_Inc TIM2_CCR1L=TIM2_CCR1L+0x01
#define BeamHigh_Dec TIM2_CCR1L=TIM2_CCR1L-0x01

#define BeamLow_Inc TIM2_CCR2L=TIM2_CCR2L+0x01
#define BeamLow_Dec TIM2_CCR2L=TIM2_CCR2L-0x01

int fBeamStatus = 0;

void Delay(int Count);

int main( void )
{
  Init_TIM();
  
  BeamLow_TIM_Start;  //TIM2 - start
 
 
  while(1)
  {  
    if(fBeamStatus == 0)
    {          
      for(int i =0; i<0xF4; i+=0x01) //пока коэфф заполнения не будет полным
      {
         BeamHigh_Inc; //заполняем(разжигаем свет)
         BeamLow_Inc;      
        Delay(200);   
      }        
       for(int i =0xF4; i>0x01; i-=0x01) //пока коэфф заполнения не станет нулевым
      {   
       BeamHigh_Dec; //убираем заполнение(тушим дальний)    
       
        Delay(150);          
      }                
      fBeamStatus = 1; 
    }
    else
    {    
      BeamLow_TIM_Stop;
    }
  }
}

//delay
void Delay(int Count)
{
  for(unsigned long delay_count = 0; delay_count < Count; delay_count++);
}