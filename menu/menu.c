//************************** DEVICE MANAGEMENT SYSTEM **************************
//  Copyright (c) 2025 Trenser Technology Solutions
//  All Rights Reserved
//******************************************************************************
//
// File		: menu.c
// Summary	: List initial menu for a menu driven system
// Note		: The next level progression based on decisions from initial menu
// Author	: Francis V D
// Date		: 22-December-2025
//
//******************************************************************************

//******************************* Include Files ********************************
#include <stdio.h>
#include <stdbool.h>
#include "customTypes.h"
#include "menu.h"
#include "device.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//****************************** Local Functions *******************************

//******************************.FUNCTION_HEADER.*******************************
//Purpose	: Display the contents in secondary menu 
//Inputs	: None
//Outputs	: None
//Return	: Return the option selected
//Notes		: The selected option is used to move to the next level
//******************************************************************************
static uint8 menuDisplaySeconadryOptions(void)
{
	uint8 ucChoice = 0;

	printf("1. Name\n");
	printf("2. Type\n");
	printf("3. Id\n");
	printf("4. Vendor\n");
	printf("0. Back to main menu\n");
	printf("Enter choice: ");
	scanf("%hhd", &ucChoice);

	return ucChoice;
}

//******************************.FUNCTION_HEADER.*******************************
//Purpose	: Display the contents in main menu 
//Inputs	: None
//Outputs	: None
//Return	: Return the option selected
//Notes		: The selected option is used to move to the next level
//******************************************************************************
static uint8 menuDisplayMainOptions(void)
{
	uint8 ucChoice = 0;

	printf("\nMenu\n");
	printf("-----------------------------\n");
	printf("1. Add device\n");
	printf("2. List devices\n");
	printf("3. Search device\n");
	printf("4. Remove device\n");
	printf("0. Exit\n");
	printf("Enter choice: ");
	scanf("%hhu", &ucChoice);

	return ucChoice;
}

//******************************.FUNCTION_HEADER.*******************************
//Purpose	: Navigte from main menu to next levels based on the 
//			  selected options
//Inputs	: None
//Outputs	: None
//Return	: True, in case of successful execution
//Return	: False, in case of any error
//Notes		: Select exit option to terminate
//******************************************************************************
bool menuMain(void)
{
	bool blReturn = false;
	uint8 ucMainChoice = 0;
	uint8 ucSecondaryChoice = 0;
	
	printf("Device Management System");

	do 
	{
		ucMainChoice = menuDisplayMainOptions();
		
		switch( ucMainChoice )
		{
			case MENU_EXIT:
			{
				printf("Exiting...\n");
			}
			break;

			case MENU_ADD:
			{
				deviceAdd(FILE_NAME);
			}
			break;

			case MENU_LIST:
			{
				deviceList(FILE_NAME); 
			}
			break;

			case MENU_SEARCH:
			{
				printf("\nSearch device\n");
				printf("-----------------------------\n");
				printf("Select the search criteria:\n");
				ucSecondaryChoice = menuDisplaySeconadryOptions();
				deviceSearch(FILE_NAME, ucSecondaryChoice);
			}
			break;

			case MENU_REMOVE:
			{
				printf("\nRemove device\n");
				printf("-----------------------------\n");
				printf("Select the removal criteria:\n");
				ucSecondaryChoice = menuDisplaySeconadryOptions();				
				deviceRemove(FILE_NAME, ucSecondaryChoice);
			}
			break;

			default:
				printf("Invalid choice!\n");
		}
	}
	while (ucMainChoice != 0);

	return blReturn;
}
// EOF
