#include "Dclock.h"
#include "stdlib.h"
#include "string.h"
#define _DCLOCK_C


void DClock_Print(void);
void DClock_Update(void);
pDClock cthis;
pDClock DClock_Create(void){
	pDClock Dclock_c = (pDClock)malloc(sizeof(pDClock));
	
	if(Dclock_c == NULL)
	{
		return NULL;
	}
	
	Dclock_c->Second = 0;
	Dclock_c->Minute = 0;
	Dclock_c->Hour = 0;
	
	Dclock_c->pDClock_Print = DClock_Print;
	Dclock_c->pDClock_Update = DClock_Update;
	
	cthis = Dclock_c;
	return Dclock_c;
}

pDClock Clock_CreateWithArgs(uint8_t Hour, uint8_t Minute, uint8_t Second){
	pDClock Dclock_c = DClock_Create();
	if(Dclock_c == NULL)
	{
		return NULL;
	}
	ImportSecond = Second;
	Dclock_c->Second = Second;
	Dclock_c->Minute = Minute;
	Dclock_c->Hour = Hour;
	
	return Dclock_c;
}

void Clock_Print(void)
{
	OLED_ShowNum(1, 1, cthis->Hour, 2);
	OLED_ShowString(1, 3, ":");
	OLED_ShowNum(1, 4, cthis->Minute, 2);
	OLED_ShowString(1, 6, ":");
	OLED_ShowNum(1, 7, cthis->Second, 2);
}

void Clock_Update(void){
	cthis->Second = ImportSecond;
	if(cthis->Second >= 60){
		cthis->Minute += cthis->Second / 60;
		cthis->Second %= 60;
		ImportSecond %= 60;
			if(cthis->Minute >= 60){
			cthis->Hour += cthis->Minute / 60;
			cthis->Minute %= 60;
				if(cthis->Hour == 24){
				cthis->Hour %= 24;
			}
		}
	}
}

