#include "iostm8s003f3.h"
//#include "iostm8l152C6.h"
#include <intrinsics.h>  //Здесь описана функция __enable_interrupt ().


void uart_init(unsigned long baud_rate, unsigned long f_master);
void uart_tx_byte(unsigned char data);
void uart_tx_data(unsigned char * data, unsigned char len);
unsigned char uart_rx_byte();
void uart_rx_data(unsigned char * data, unsigned char len);


// Обработчик прерываний по приему UART
#pragma vector=UART1_R_RXNE_vector 
__interrupt void uart_rx_interrupt(void)
{
  unsigned char data;
   
  data = UART1_DR;
   
  //Отсылаем принятый байт обратно
  uart_tx_byte(data);
}

void Delay(long Delay)
{
  for(unsigned long i = 0; i < Delay; i++);
}

void uart_init(unsigned long baud_rate, unsigned long f_master)
{
   
  //Значение регистра BRR
  unsigned long brr;
   
  //Настраиваем TX на выход, а RX на вход
  PD_DDR_bit.DDR5 = 1;  //TX
  PD_DDR_bit.DDR6 = 0;  //RX
   
  //RX - плавающий вход
  PD_CR1_bit.C16 = 0;
  //Отключает внешние прерывания для RX
  PD_CR2_bit.C26 = 0;
   
  //Настройка скорости передачи
  brr = f_master/baud_rate;
     
  UART1_BRR2 = brr & 0x000F;
  UART1_BRR2 |= brr >> 12;
  UART1_BRR1 = (brr >> 4) & 0x00FF;   
  
  //Четность отключена
  UART1_CR1_PIEN = 0;
  //Контроль четности отключен
  UART1_CR1_PCEN = 0;
  //8-битный режим
  UART1_CR1_M = 0;
  //Включить UART
  UART1_CR1_UART0 = 0;
   
  //Запретить прерывание по опустошению передающ. регистра
  UART1_CR2_TIEN = 0;
  //Запретить прерывание по завершению передачи
  UART1_CR2_TCIEN = 0;
  //Запретить прерывание по заполнению приемного регистра
  UART1_CR2_RIEN = 1;
  //Запретить прерывание по освобождению линии
  UART1_CR2_ILIEN = 0;
  //Передатчик включить
  UART1_CR2_TEN = 1;
  //Приемник включить
  UART1_CR2_REN = 1;
  //Не посылать break-символ
  UART1_CR2_SBK = 0;
   
  //Один стоп-бит
  UART1_CR3_STOP = 0;
}

int main()
{        
  unsigned char data;
  
   
 //uart_init(UART_BAUD_RATE, F_MASTER);
  uart_init(9600, 1000000);
  
   
  uart_tx_data("Hello, world!\r\n", 15); 
  __enable_interrupt();

   
  while(1)
  {
  //  uart_rx_data(&data, 1);
   //   uart_tx_data(&data, 1);   
  }
}

// Отправка байта
void uart_tx_byte(unsigned char data)
{
    while(!UART1_SR_TXE);
    UART1_DR = data;
}
 
// Отправка массива данных
void uart_tx_data(unsigned char * data, unsigned char len)
{
  while(len--){
      uart_tx_byte(*data++);
  }
}
// Прием байта
unsigned char uart_rx_byte()
{
    unsigned char data;
       
    while(!UART1_SR_RXNE);
    data = UART1_DR;
    return data;
}
 
// Прием массива данных
void uart_rx_data(unsigned char * data, unsigned char len)
{
  while(len--){
      *data++ = uart_rx_byte();
  }
}
