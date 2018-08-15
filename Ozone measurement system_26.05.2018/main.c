#include "main.h"
//#include "iostm8l152C6.h"

//Добавить АЦП,передача данных ацп, ноги для клапанов

void uart_init(unsigned long baud_rate, unsigned long f_master);
void uart_tx_byte(unsigned char data);
void uart_tx_data(unsigned char * data, unsigned char len);
unsigned char uart_rx_byte();
void uart_rx_data(unsigned char * data, unsigned char len);
int ExpStart();
int ReadInMess();


int g_ReadInMess = 1; //Show when we have unread message, 0 - have unread
int g_aInMess[10] = {0};
int *g_InMess = &g_aInMess[0];
int g_MessNumber = 0;    //Number write position
int g_ExpTime = 0;   //Exp time in Second
int g_StartStopExp = 0;   //if 0 - stop, 1 - start

int msecond = 0;
int milesecond = 0;
int second = 0;
int minute = 0;

// Обработчик прерываний по приему UART
#pragma vector=UART2_R_RXNE_vector 
__interrupt void uart2_rx_interrupt(void)
{   
  if(UART2_SR_RXNE)
  {
   g_aInMess[g_MessNumber] = UART2_DR;
   g_ReadInMess = 0;
   g_MessNumber++;     
   if(g_aInMess[0] == '1' && g_aInMess[1] == '0')
   {
     g_StartStopExp = 0;
     g_MessNumber = 0;
   }
   if(g_MessNumber >=9)
   {
     g_MessNumber = 0;
   }
  }
   
   
  //Отсылаем принятый байт обратно
  //uart_tx_byte(data);
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
       if(second >= 60)
       {
         second = 0;
         minute ++;
       }
      }
    }  
  }    
}

void Delay(long Delay)
{
  for(unsigned long i = 0; i < Delay; i++)
  {
  if(g_StartStopExp == 0)
    break;  
  }
}



int main()
{        
 // unsigned char data;
  
   
 //uart_init(UART_BAUD_RATE, F_MASTER);
  uart_init(9600, 16000000);
  Init_TIM();
  Init_GPIO();
   
 // uart_tx_data("Hello, world!\r\n", 15); 
  __enable_interrupt();
//Delay(1);
   uart_tx_data("01",2);  // We ready to work
   
   
   
   
  while(1)
  {
    if(g_ReadInMess == 0 && g_MessNumber >= 6)
    {      
      ReadInMess();    
      g_ReadInMess = 1;  //reset flag, we readed mess
      g_MessNumber = 0; //reset write pos  
    }
    if(g_StartStopExp == 1)
    {
      ExpStart();
    }
  }
}

int ReadInMess()
{
//if(g_aInMess[6] == '\n')
 {
  int CRCVal = '0';
//  for(int i =0; i<5; i++)    
//  CRCVal = (CRCVal + g_aInMess[i]*211)/123;
  
if(CRCVal == g_aInMess[5])   //Check CRC
 {
  //Приемник выключить
  UART2_CR2_REN = 0;  
  
  //Check CRC
  if(g_aInMess[0] == '0')  //Setting part
  {
    if(g_aInMess[1] == '0')  //Setting for first PWM
    {
      TIM2_CCR1L= 2*((g_aInMess[2]-48)*100 + (g_aInMess[3]-48)*10 + (g_aInMess[4]-48));  //[0;244]
      
    }
    
    if(g_aInMess[1] == '1')  //Sett for Second PWM
    {
      TIM2_CCR2L= 2*((g_aInMess[2]-48)*100 + (g_aInMess[3]-48)*10 + (g_aInMess[4]-48));  //[0;244]
    }     
    uart_tx_data("00'\n'",2);  // answer OK
    //Приемник включить
    UART2_CR2_REN = 1;
     return 1;
  }
  if(g_aInMess[0] == '1') //Control part
  {
    if(g_aInMess[1] == '1') //Start Exp
    {
       if(g_aInMess[2] == '1')   //Get ADC value
       {
         g_ExpTime = (g_aInMess[3]-48)*10 + (g_aInMess[4]-48);  //exp time [0;99] minute
         //Start ADC
         //Start Send ADC in mess         
         g_StartStopExp = 1; //Start Exp
         //Приемник включить
          UART2_CR2_REN = 1;
         return 1;
       }
       if(g_aInMess[2] == '0')   //Don't get ADC value, start
       {
         g_ExpTime = (g_aInMess[3]-48)*10 + (g_aInMess[4]-48);
         //Start EXP
         g_StartStopExp = 1;
         //clear array
         for(int i=0; i<6; i++)
         {
           g_aInMess[i] = 0;
         }
         //Приемник включить
        UART2_CR2_REN = 1;
         return 1;        
       }
     }
    
    if(g_aInMess[1] == '0')  //Stop Exp
    {
     //Stop Exp 
      g_StartStopExp = 0;    
      //Приемник включить
      UART2_CR2_REN = 1;
      return 1;
    }
  }
  
   uart_tx_data("00'\n'",2);  // answer OK, we readed mess
  
   //Приемник включить
  UART2_CR2_REN = 1;
 }  
  return 0;
 }
  return 0;
}


int ExpStart()
{
  int Time = 0;  
  TIM4_CR1_CEN = 1;  //TIM4 - start
  TIM2_CR1_CEN = 1;
  PC_ODR_bit.ODR7 = 1;                        //ON Relay
  Delay(150000);                         //Heating Ozonator
  PC_ODR_bit.ODR4 = 1;                        //ON Valve 1
  PC_ODR_bit.ODR5 = 1;                        //ON Valve 2
  PC_ODR_bit.ODR6 = 1;                        //ON Valve 3(work zone)
   
   for(int i=0; i<6; i++)
   {
    g_aInMess[i] = 0;
   }
   g_MessNumber = 0;
   
  while((g_ExpTime >= minute) && g_StartStopExp == 1)
  {
    //Send ADC Mess if we have flag
    Time = minute;
  }  
   TIM4_CR1_CEN = 0;  //TIM4 - stop   
  msecond = milesecond = second = minute = 0;  
  PC_ODR_bit.ODR7 = 0;                        //Off Relay  
  PC_ODR_bit.ODR4 = 0;                        //ON Valve 1
  PC_ODR_bit.ODR5 = 0;                        //Off Valve 2
  PC_ODR_bit.ODR7 = 0;                        //Off Relay  
  Delay(150000);  
  PC_ODR_bit.ODR6 = 0;                        //Off Valve 3(work zone)  
  TIM2_CCR2L = TIM2_CCR1L = 0x01;  
  Delay(10);
 // PD_ODR_bit.ODR3 = 0;
 // PD_ODR_bit.ODR4 = 0;
  TIM2_CR1_CEN = 0;  
  g_StartStopExp = 0;    //Stop exp
  for(int i=0; i<6; i++)
   {
    g_aInMess[i] = 0;
   }
  g_MessNumber = 0;
  uart_tx_data("00'\n'",2);
  
  return Time; //return work Experimental  time(in minutes)
}