
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "add_Employee.h"
#include "ArrayEmployees.h"
#include "Inputs.h"




void opcionDarDeAltaEmpleado(Employee* list, int length, int* contadorAltas) 		// CAMBIARLE EL NOMBRE A LAS VARIABLES AUXILIARES ---PONERLAS EN INGLES---
{
	int idResult;
	int idCounter = 0;
	char cadenaNombre[MAX_STRING_LENGHT];
	char cadenaApellido[MAX_STRING_LENGHT];
	float salario;
	int sectorCopy;
	int seguirIngresandoAlta;


	do
	{
		if ( !enterEmployeeData(list, length, &idResult, idCounter, cadenaNombre, cadenaApellido, &salario, &sectorCopy) )
		{
			addEmployee(list, length, idResult, cadenaNombre, cadenaApellido, salario, sectorCopy);

			idCounter++;
			(*contadorAltas)++;

			seguirIngresandoAlta = getIntInMinMaxRange("Do you want to enter another employee?:\n\n"
													   "1. Keep entering employees\n"
													   "0. Back to Main Menu\n\n\n\n\n",

													   "\n\nError - reason: [Invalid option]\n"
													   "Please enter an option again\n"
													   "1. Keep entering employees\n"
													   "0. Back to Main Menu\n\n\n", 0, 1);

		}
		else
		{
			break;
		}

	} while (seguirIngresandoAlta);


}




// PIDE INFORMACION A EMPLEADOS
int enterEmployeeData(Employee* list, int length, int* id, int idCounter, char* name, char* lastName, float* salary, int* sector)
{
	int returnValue = -1;

	if (list != NULL && length > -1)
	{

		if (getEmptySpaceInArray(list, length) != -1)
		{

			printf("\n\n************************************************************************************************\n\n"
					"Entering a new employee...\n"
					"Please fill in the fields\n\n"
					"************************************************************************************************\n\n");

			*id = generateId(idCounter);
			getString(name, "Enter name: ", "Error. Please enter name again: ", MAX_STRING_LENGHT);
			getString(lastName, "Enter last name: ", "Error. Please enter last name again: ", MAX_STRING_LENGHT);
			*salary = getFloatInMinMaxRange("Enter salary: ", "Error. Please enter salary again: ", 0, MAX_SALARY);
			*sector = getIntInMinMaxRange("Enter sector: ", "Error. Please enter sector again: ", 0, MAX_SECTOR);

			returnValue = 0;

		}
		else
		{
			printf("\n------------------------------------------------------------------------------------------------\n"
					"Error - reason: [No empty space to enter an employee...]\n"
					"------------------------------------------------------------------------------------------------\n\n\n");
		}

	}


	return returnValue;
}



// BUSCA ESPACIO LIBRE EN EL ARRAY ---> DEVUELVE EL SUBINDICE (INDEX)
int getEmptySpaceInArray(Employee* list, int len)
{
	int index = -1;

	for (int i = 0; i < len; ++i)
	{
		if (list[i].isEmpty == TRUE)
		{
			index = i;
			break;
		}
	}
	return index;
}




// GENERA UN ID
int generateId(int idCounter)
{
	int generatedId;

	if (idCounter == 0)
	{
		generatedId = ID;
	}
	else
	{
		generatedId = ID + idCounter;
	}

	return generatedId;
}


























