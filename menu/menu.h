//************************** DEVICE MANAGEMENT SYSTEM **************************
//  Copyright (c) 2025 Trenser Technology Solutions
//  All Rights Reserved
//******************************************************************************
//
// Summary	: To manage a menu in a device management system
// Note		: Handle different menus for device management system
//
//******************************************************************************

#ifndef MENU_H
#define MENU_H

//******************************* Include Files ********************************
#include <stdbool.h>
#include "customTypes.h"

//******************************* Global Types *********************************
#define SEARCH_CRITERIA_MAXIMUM_OPTIONS (4)
#define REMOVE_CRITERIA_MAXIMUM_OPTIONS (4)

//***************************** Global Constants *******************************

//***************************** Global Variables *******************************
typedef enum{
	MENU_EXIT,
	MENU_ADD,
	MENU_LIST,
	MENU_SEARCH,
	MENU_REMOVE
}MENU_OPTIONS;

typedef enum{
	BACK_TO_MAIN_MENU,
	SEARCH_BY_NAME,
	SEARCH_BY_TYPE,
	SEARCH_BY_ID,
	SEARCH_BY_VENDOR
}SEARCH_OPTIONS;

//**************************** Forward Declarations ****************************
bool menuMain(void);

#endif // MENU_H
// EOF