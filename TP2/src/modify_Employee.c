
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "modify_Employee.h"
#include "ArrayEmployees.h"
#include "Inputs.h"



void subMenuModificaciones(Employee* list, int len, int contadorAltas)
{
	int idForSearch;
	int indexPositionForSearch;
	int subMenuOption;

	if (contadorAltas > 0)
	{

		printEmployees(list, len);

		idForSearch = getNumeroMayorQueMinimo("\n\n************************************************************************************************\n\n"
											  "Enter employee ID that you want to modify: \n\n"
											  "************************************************************************************************\n\n",

											  "Error - reason: [Invalid ID]\n"
											  "Please enter employee ID again: \n", ID);

		indexPositionForSearch = findEmployeeById(list, len, idForSearch);

		if (indexPositionForSearch != -1)
		{
			do {
				subMenuOption = getIntInMinMaxRange("\n\nMODIFICATION MENU\n"
													"------------------------------------------------------------------------------------------------\n"
													"What do you want to modify?\n\n"
													"1. Employee Name\n"
													"2. Employee Last Name\n"
													"3. Employee Salary\n"
													"4. Employee Sector\n\n"
													"5. Back to Main Menu\n"
													"------------------------------------------------------------------------------------------------\n",

													"\n\nError - reason: [Invalid option]\n"
													"Please enter an option again.\n"
													"Modification Menu\n"
													"------------------------------------------------------------------------------------------------\n"
													"What do you want to modify?\n"
													"1. Employee Name\n"
													"2. Employee Last Name\n"
													"3. Employee Salary\n"
													"4. Employee Sector\n\n"
													"5. Back to Main Menu\n"
													"------------------------------------------------------------------------------------------------\n\n", 1, 5);


				switch(subMenuOption)
				{
					case 1:
						modifyName(list, len, indexPositionForSearch);
						break;

					case 2:
						modifyLastName(list, len, indexPositionForSearch);
						break;

					case 3:
						modifySalary(list, len, indexPositionForSearch);
						break;

					case 4:
						modifySector(list, len, indexPositionForSearch);
						break;

					case 5:
						// Exit SubMenu
						break;
				}

			} while (subMenuOption != 5);

		}
	}
	else
	{
		printf("\n------------------------------------------------------------------------------------------------\n"
				"Error. Do not allowed modifications - reason: [No employee loaded in system]\n"
				"------------------------------------------------------------------------------------------------\n\n\n\n");
	}


}



// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// FUNCIONES PARA MODIFICAR DATOS
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void modifyName(Employee* list, int len, int indexPosition)
{
	char newName[MAX_STRING_LENGHT];

	if (list != NULL && len > -1)
	{
		getString(newName, "Enter employee new name: ", "Error - reason: [Invalid name]. Please enter name again: ", MAX_STRING_LENGHT);
		strcpy(list[indexPosition].name, newName);
		printf("\n________________________________________________________________________________________________\n\n"
				"Employee name changed successfully!...\n"
				"________________________________________________________________________________________________\n\n\n");
	}
	else
	{
		printf("\n------------------------------------------------------------------------------------------------\n"
				"Error - reason: [Invalid length or NULL pointer...]\n\n"
				"------------------------------------------------------------------------------------------------\n\n\n");
	}
}




void modifyLastName(Employee* list, int len, int indexPosition)
{
	char newLastName[MAX_STRING_LENGHT];

	if (list != NULL && len > -1)
	{
		getString(newLastName, "Enter employee new last name: ", "Error - reason: [Invalid last name]. Please enter last name again: ", MAX_STRING_LENGHT);
		strcpy(list[indexPosition].lastName, newLastName);
		printf("\n________________________________________________________________________________________________\n\n"
				"Employee last name changed successfully!...\n"
				"________________________________________________________________________________________________\n\n\n");
	}
	else
	{
		printf("\n------------------------------------------------------------------------------------------------\n"
				"Error - reason: [Invalid length or NULL pointer...]\n\n"
				"------------------------------------------------------------------------------------------------\n\n\n");
	}
}




void modifySalary(Employee* list, int len, int indexPosition)
{
	float newSalary;

	if (list != NULL && len > -1)
	{
		newSalary = getFloatInMinMaxRange("Enter employee new salary: ", "Error - reason: [Invalid salary]. Please enter salary again: ", 0, MAX_SALARY);
		list[indexPosition].salary = newSalary;
		printf("\n________________________________________________________________________________________________\n\n"
				"Employee salary changed successfully!...\n"
				"________________________________________________________________________________________________\n\n\n");
	}
	else
	{
		printf("\n------------------------------------------------------------------------------------------------\n"
				"Error - reason: [Invalid length or NULL pointer...]\n\n"
				"------------------------------------------------------------------------------------------------\n\n\n");
	}
}



void modifySector(Employee* list, int len, int indexPosition)
{
	int newSector;

	if (list != NULL && len > -1)
	{
		newSector = getIntInMinMaxRange("Enter employee new sector: ", "Error - reason: [Invalid sector]. Please enter sector again: ", 1, MAX_SECTOR);
		list[indexPosition].sector = newSector;
		printf("\n________________________________________________________________________________________________\n\n"
				"Employee sector changed successfully!...\n"
				"________________________________________________________________________________________________\n\n\n");
	}
	else
	{
		printf("\n------------------------------------------------------------------------------------------------\n"
				"Error - reason: [Invalid length or NULL pointer...]\n\n"
				"------------------------------------------------------------------------------------------------\n\n\n");
	}
}
