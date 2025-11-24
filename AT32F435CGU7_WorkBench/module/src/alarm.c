#include "alarm.h"

#define ERROR_THRESHOLD 100

int error_counter;
int error_test;

float recent_Dg_X;
float recent_Dg_Y;
float recent_Dg_Z;
float recent_Acc_X;
float recent_Acc_Y;
float recent_Acc_Z;

void alarm(void)
{
	gpio_bits_set(GPIOC, GPIO_PINS_13);
}

/*
目前仅考虑数据保持不变的情况，后续按需求可以加入范围的判断
*/
void err_check(const Fog_Transmit_t* transmit)
{
	if(error_counter == ERROR_THRESHOLD)
		return;
	if (transmit->Dg_X == recent_Dg_X || transmit->Dg_Y == recent_Dg_Y || transmit->Dg_Z == recent_Dg_Z ||
			transmit->Acc_X == recent_Acc_X || transmit->Acc_Y == recent_Acc_Y || transmit->Acc_Z == recent_Acc_Z)
		error_counter++;
	else
	{
		recent_Dg_X = transmit->Dg_X;
		recent_Dg_Y = transmit->Dg_Y;
		recent_Dg_Z = transmit->Dg_Z;
		recent_Acc_X = transmit->Acc_X;
		recent_Acc_Y = transmit->Acc_Y;
		recent_Acc_Z = transmit->Acc_Z;
		error_counter = 0;
	}
	if(error_counter == ERROR_THRESHOLD)
		alarm();
}

void err_test(const Fog_Transmit_t* transmit)
{
	if (transmit->Dg_X == recent_Dg_X)
			//transmit->Acc_X == recent_Acc_X || transmit->Acc_Y == recent_Acc_Y || transmit->Acc_Z == recent_Acc_Z)
		error_test++;
}
