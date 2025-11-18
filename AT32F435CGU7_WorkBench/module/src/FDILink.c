#include "FDILink.h"

void FDILink_Reset(FDILink_t* FDILink)
{
	FDILink->RxStatus = FDILink_Frame_Start;
	FDILink->BufferIndex = 0;
	FDILink->CRC_FOG = 0;
}

void FDILink_Error(FDILink_t* FDILink,int Error_Counter)
{
	FDILink->RxStatus = FDILink_Frame_Start;
	Error_Counter++;
}
