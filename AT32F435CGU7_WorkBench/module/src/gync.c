#include "gync.h"

IXZ_F50X_t IXZ_F50X_X;
IXZ_F50X_t IXZ_F50X_Y;
IXZ_F50X_t IXZ_F50X_Z;

void gync_x_handler(const uint8_t *data)
{
	IXZ_F50X_X.Dg_raw = data[1] & 0x7f;
	IXZ_F50X_X.Dg_raw |= (unsigned int)(data[2] & 0x7f) << 7;
	IXZ_F50X_X.Dg_raw |= (unsigned int)(data[3] & 0x7f) << 14;
	IXZ_F50X_X.Dg_raw |= (unsigned int)(data[4] & 0x7f) << 21;
	IXZ_F50X_X.Dg_raw |= (unsigned int)(data[5] & 0x0f) << 28;
	
	IXZ_F50X_X.Temp_raw  =  data[7] & 0x7f;
	IXZ_F50X_X.Temp_raw |= (unsigned short)(data[8] & 0x7f) << 7;   

	IXZ_F50X_X.Dg		= 	((float)IXZ_F50X_X.Dg_raw / (F50X_X_PPM/TIM_TRANSMIT_HZ)); 
	IXZ_F50X_X.Temp =		IXZ_F50X_X.Temp_raw;
}

void gync_y_handler(const uint8_t *data)
{
	IXZ_F50X_Y.Dg_raw = data[1] & 0x7f;	
	IXZ_F50X_Y.Dg_raw |= (unsigned int)(data[2] & 0x7f) << 7;
	IXZ_F50X_Y.Dg_raw |= (unsigned int)(data[3] & 0x7f) << 14;
	IXZ_F50X_Y.Dg_raw |= (unsigned int)(data[4] & 0x7f) << 21;
	IXZ_F50X_Y.Dg_raw |= (unsigned int)(data[5] & 0x0f) << 28;
	
	IXZ_F50X_Y.Temp_raw = data[7] & 0x7f;
	IXZ_F50X_Y.Temp_raw |= (unsigned short)(data[8] & 0x7f) << 7;

	IXZ_F50X_Y.Dg		= 	((float)IXZ_F50X_Y.Dg_raw / (F50X_Y_PPM / TIM_TRANSMIT_HZ));
	IXZ_F50X_Y.Temp =		IXZ_F50X_Y.Temp_raw;
}

void gync_z_handler(const uint8_t *data)
{
	IXZ_F50X_Z.Dg_raw = data[1] & 0x7f;	
	IXZ_F50X_Z.Dg_raw |= (unsigned int)(data[2] & 0x7f) << 7;	
	IXZ_F50X_Z.Dg_raw |= (unsigned int)(data[3] & 0x7f) << 14;	
	IXZ_F50X_Z.Dg_raw |= (unsigned int)(data[4] & 0x7f) << 21;	
	IXZ_F50X_Z.Dg_raw |= (unsigned int)(data[5] & 0x0f) << 28;	
		
	IXZ_F50X_Z.Temp_raw = data[7] & 0x7f;	
	IXZ_F50X_Z.Temp_raw |= (unsigned short)(data[8] & 0x7f) << 7;
	
	IXZ_F50X_Z.Dg		= 	((float)IXZ_F50X_Z.Dg_raw / (F50X_Z_PPM / TIM_TRANSMIT_HZ));
	IXZ_F50X_Z.Temp =		IXZ_F50X_Z.Temp_raw;
}
