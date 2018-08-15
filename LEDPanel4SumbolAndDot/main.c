#include "iostm8s105c6.h"
/*------------------------------------------------
Засовыет в себя значение пина DS при появлении HIGH сигнала на ноге SH_CP
 записывает в регистр хранения при появлении HIGH level на ST.
-------------------------------------------------*/
// SH_CP PD[2] - Leg for clocking impulse
// DS    PD[3] - Output data leg 
// ST_CP  PD[4] - Fixing data register

//========================================              Define leg
#define SH_CP   PD_ODR_bit.ODR2
#define DS      PD_ODR_bit.ODR3
#define ST_CP   PD_ODR_bit.ODR4
//------------------------------------- Symbol Array
//              KATOD
int Symbol_Katod_Zero[] =  {0,1,1,1,0,1,1,1,0};
int Symbol_Katod_One[] =   {0,0,1,0,0,1,0,0,0};
int Symbol_Katod_Two[] =   {0,1,0,1,1,1,1,0,0};
int Symbol_Katod_Three[] = {0,1,1,0,1,1,1,0,0};
int Symbol_Katod_Four[] =  {0,0,1,0,1,1,0,1,0};
int Symbol_Katod_Five[] =  {0,1,1,0,1,0,1,1,0};
int Symbol_Katod_Six[] =   {0,1,1,1,1,0,1,1,0};
int Symbol_Katod_Seven[] = {0,0,1,0,0,1,1,0,0};
int Symbol_Katod_Eight[] = {0,1,1,1,1,1,1,1,0};
int Symbol_Katod_Nine[] =  {0,1,1,0,1,1,1,1,0};

int Symbol_Katod_Zero_Dot[] =  {1,1,1,1,0,1,1,1,0};
int Symbol_Katod_One_Dot[] =   {1,0,1,0,0,1,0,0,0};
int Symbol_Katod_Two_Dot[] =   {1,1,0,1,1,1,1,0,0};
int Symbol_Katod_Three_Dot[] = {1,1,1,0,1,1,1,0,0};
int Symbol_Katod_Four_Dot[] =  {1,0,1,0,1,1,0,1,0};
int Symbol_Katod_Five_Dot[] =  {1,1,1,0,1,0,1,1,0};
int Symbol_Katod_Six_Dot[] =   {1,1,1,1,1,0,1,1,0};
int Symbol_Katod_Seven_Dot[] = {1,0,1,0,0,1,1,0,0};
int Symbol_Katod_Eight_Dot[] = {1,1,1,1,1,1,1,1,0};
int Symbol_Katod_Nine_Dot[] =  {1,1,1,0,1,1,1,1,0};

int Symbol_Katod_Dot[] =   {1,0,0,0,0,0,0,0,0};

int Symbol_Katod_Clear[] =   {0,0,0,0,0,0,0,0,0};
//              ANOD
int Symbol_Anod_One[] =  {0,0,0,0,0,0,1,1,1};
int Symbol_Anod_Two[] =  {0,0,0,0,0,1,0,1,1};
int Symbol_Anod_Three[] =  {0,0,0,0,0,1,1,0,1};
int Symbol_Anod_Four[] =  {0,0,0,0,0,1,1,1,0};
 
//-----------------------------         END PART

void ShiftRegister(int value);
void Init_74HC595(void);

int main( void )
{

  Init_74HC595();  
  for(int i = 0; i <=8; i++)
  {
    ShiftRegister(Symbol_Anod_Two[i]);    
  }
  for(int i = 0; i <=8; i++)
  {
    ShiftRegister(Symbol_Katod_Clear[i]);    
  }
  ST_CP = 1; // Fixing Data
  while(1); 
  
}

void ShiftRegister(int value)
{
   ST_CP = 0;    //Leg to Write data
   SH_CP = 1;   //Clocking Write Impulse
   DS = value;  //Writing bits
   SH_CP = 0;   //Clocking Ended impulse
  
}