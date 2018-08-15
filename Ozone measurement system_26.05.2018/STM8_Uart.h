//#include "iostm8s003f3.h"
#include "iostm8s105c6.h"

void uart_init(unsigned long baud_rate, unsigned long f_master);
void uart_tx_byte(unsigned char data);
void uart_tx_data(unsigned char * data, unsigned char len);
unsigned char uart_rx_byte();
void uart_rx_data(unsigned char * data, unsigned char len);