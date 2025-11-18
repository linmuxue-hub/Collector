#ifndef __FDILINK_H
#define __FDILINK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "at32f435_437.h"

/*
FDILink_Frame_Start	---	帧头
FDILink_Frame_CMD		---	次帧
FDILink_Frame_Data	---	数据帧
FDILink_Frame_End		---	帧尾
FDILink_Frame_Error	---	出错
*/
typedef enum
{
  FDILink_Frame_Start = 0,
  FDILink_Frame_CMD,
  FDILink_Frame_Data,
  FDILink_Frame_End,
  FDILink_Frame_Error
} FDILink_FrameStatus_t;

/*
RxStatus		---	当前接收状态
Buffer			---	数据缓存
BufferIndex	---	已接收数据长度
RxDataLeft	---	预期接收数据长度
CRC					---	校验码，奇偶校验
*/
typedef struct
{
  FDILink_FrameStatus_t RxStatus;
  uint8_t Buffer[64];
  uint8_t BufferIndex;
	uint8_t RxDataLeft;
  uint8_t CRC_FOG;
} FDILink_t;

void FDILink_Reset(FDILink_t* FDILink);
void FDILink_Error(FDILink_t* FDILink,int Error_Counter);

#ifdef __cplusplus
}
#endif

#endif
