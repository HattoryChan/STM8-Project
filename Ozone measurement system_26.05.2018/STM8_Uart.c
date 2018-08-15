#include "STM8_Uart.h"


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
     
  UART2_BRR2 = brr & 0x000F;
  UART2_BRR2 |= brr >> 12;
  UART2_BRR1 = (brr >> 4) & 0x00FF;   
  
  //Четность отключена
  UART2_CR1_PIEN = 0;
  //Контроль четности отключен
  UART2_CR1_PCEN = 0;
  //8-битный режим
  UART2_CR1_M = 0;
  //Включить UART
  UART2_CR1_UART0 = 0;
   
  //Запретить прерывание по опустошению передающ. регистра
  UART2_CR2_TIEN = 0;
  //Запретить прерывание по завершению передачи
  UART2_CR2_TCIEN = 0;
  //Запретить прерывание по заполнению приемного регистра
  UART2_CR2_RIEN = 1;
  //Запретить прерывание по освобождению линии
  UART2_CR2_ILIEN = 0;
  //Передатчик включить
  UART2_CR2_TEN = 1;
  //Приемник включить
  UART2_CR2_REN = 1;
  //Не посылать break-символ
  UART2_CR2_SBK = 0;
   
  //Один стоп-бит
  UART2_CR3_STOP = 0;
}


// Отправка байта
void uart_tx_byte(unsigned char data)
{
    while(!UART2_SR_TXE);
    UART2_DR = data;
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
       
    while(!UART2_SR_RXNE);
    data = UART2_DR;
    return data;
}
 
// Прием массива данных
void uart_rx_data(unsigned char * data, unsigned char len)
{
  while(len--){
      *data++ = uart_rx_byte();
  }
}