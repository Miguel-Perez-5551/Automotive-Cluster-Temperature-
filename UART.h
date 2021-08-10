/*
 * UART.h
 *
 *  Created on: 21 jul. 2021
 *      Author: danov
 */

#ifndef UART_H_
#define UART_H_

void UART_vfnDriverInit (void);
void UART_bfnRead (unsigned char *bpRxData);
void UART_bfnSend (unsigned char bTxData);





#endif /* UART_H_ */
