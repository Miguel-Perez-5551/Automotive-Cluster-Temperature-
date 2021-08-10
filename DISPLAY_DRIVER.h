/*
 * DISPLAY_DRIVER.h
 *
 *  Created on: 22 jun. 2021
 *      Author: danov
 */

#ifndef DISPLAY_DRIVER_H_
#define DISPLAY_DRIVER_H_

extern void DPY_vfnDriverInit(void);
extern void DPY_bfnWriteMsg(unsigned char *bpMsgSrc);
extern void Delay(long n);
void RENGLON1(void);
void RENGLON2(void);

#endif /* DISPLAY_DRIVER_H_ */
