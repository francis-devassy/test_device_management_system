//************************** DEVICE MANAGEMENT SYSTEM **************************
//  Copyright (c) 2025 Trenser Technology Solutions
//  All Rights Reserved
//******************************************************************************
//
// Summary	: Handle options to update device data history
// Note		: Feature to add, list, search and remove devices to the data 
//			  history
//
//******************************************************************************

#ifndef DEVICE_H
#define DEVICE_H

//******************************* Include Files ********************************
#include <stdbool.h>
#include "customTypes.h"

//******************************* Global Types *********************************
typedef struct _DEVICE_DETAILS_
{
	uint8 pucDeviceName[32];
	uint8 pucDeviceType[32];
	uint32 ulDeviceId;
	uint32 ulDeviceVendor;
	uint32 ulDeviceSerial;
} DEVICE_DETAILS;

//***************************** Global Constants *******************************

//***************************** Global Variables *******************************
#define FILE_NAME ("devices.dat")

//**************************** Forward Declarations ****************************
bool deviceAdd(const uint8 *pucFileName);
bool deviceList(const uint8 *pucFileName);
bool deviceSearch(const uint8 *pucFileName, uint32 ucChoice);
bool deviceRemove(const uint8 *pucFileName, uint32 ucId);


#endif // DEVICE_H
// EOF
