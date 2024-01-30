#ifndef __DCLOCK_H
#define __DCLOCK_H

#include "stm32f4xx.h"
#include "oled.h"

extern uint8_t ImportSecond;
typedef struct DClock *pDClock;
typedef struct DClock{
	uint8_t Second;
	uint8_t Minute;
	uint8_t Hour;
	
	void (*pDClock_Update)(void);
	void (*pDClock_Print)(void);
}DClock;

extern void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
extern void OLED_ShowString(uint8_t Line, uint8_t Column, char *String);

pDClock Clock_Create(void);
pDClock Clock_CreateWithArgs(uint8_t Second, uint8_t Minute, uint8_t Hour);

#endif

