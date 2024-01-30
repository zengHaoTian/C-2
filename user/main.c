#include "stm32f4xx.h"
#include "delay.h"
#include "led.h"
#include "oled.h"
#include "DClock.h"


extern uint8_t ImportSecond;

int main(void){
	
	Led_Init();
	OLED_Init();
	Timer_Init();
	pDClock DClock = DClock_CreateWithArgs(23, 59, 56);
	
	while(1){
		DClock->pDClock_Update();
		DClock->pDClock_Print();
	}
}
