#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "Inputs.h"


// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// FUNCIONES IMPRESCINDIBLES
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * @fn int initEmployees(Employee*, int)
 * @brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * @param list Employee* Pointer to array of employees
 * @param len int Array length
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int initEmployees(Employee* list, int len)
{
	int functionReturn = -1;

	if (list != NULL || len < -1) 			// LEN < -1 ???
	{
		for (int i = 0; i < len; ++i)
		{
			list[i].isEmpty = TRUE;
		}

		functionReturn = 0;
	}
	else
	{
		printf("Invalid length or NULL pointer...\n\n");
	}

	return functionReturn;
}


/**
 * @fn int addEmployee(Employee*, int, int, char[], char[], float, int)
 * @brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * @param list employee*
 * @param len int
 * @param id int
 * @param name[] char
 * @param lastName[] char
 * @param salary float
 * @param sector int
 * @return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
	int returnValue = -1;
	int index;

	if (list != NULL)
	{
		index = getEmptySpaceInArray(list, len);

		list[index].id = id;
		strcpy(list[index].name, name);
		strcpy(list[index].lastName, lastName);
		list[index].salary = salary;
		list[index].sector = sector;
		list[index].isEmpty = FALSE;

		printf("\nEmployee %s %s, was added successfully!\n", list[index].name, list[index].lastName);
		returnValue = 0;
	}
	else
	{
		printf("\n[Invalid length or NULL pointer or without free space]\n\n");
	}

	return returnValue;
}


/**
 * @fn int findEmployeeById(Employee*, int, int)
 * @brief find an Employee by Id and returns the index position in array.
 *
 * @param list Employee*
 * @param len int
 * @param id int
 * @return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 */
int findEmployeeById(Employee* list, int len, int id)
{
	int employeeIndexPosition = -1;

	if (list != NULL)
	{
		for (int i = 0; i < len; ++i)
		{
			if (id == list[i].id)
			{
				employeeIndexPosition = i;
				break;
			}
		}

		if (employeeIndexPosition == -1)
		{
			printf("\n[Error - Reason: [Employee not found]\n\n");
		}

	}
	else
	{
		printf("\n[Error - Reason: [Invalid length or NULL pointer received]\n\n");
	}

	return employeeIndexPosition;
}




/**
 * @fn int removeEmployee(Employee*, int, int)
 * @brief Remove an Employee by Id (put isEmpty Flag in 1)
 *
 * @param list Employee*
 * @param len int
 * @param id int
 * @return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 */
int removeEmployee(Employee* list, int len, int id) {
	 return -1;
}


/**
 * @fn int sortEmployees(Employee*, int, int)
 * @brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 * @param list Employee*
 * @param len int
 * @param order int [1] indicate UP - [0] indicate DOWN
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortEmployees(Employee* list, int len, int order) {
	 return 0;
}


/**
 * @fn int printEmployees(Employee*, int)
 * @brief print the content of employees array
 *
 * @param list Employee*
 * @param length int
 * @return int
 */
int printEmployees(Employee* list, int length)
{
	int functionValue = -1;;

	if (list != NULL)
	{
		printf("\n\n%-10s %-20s %-20s %-20s %-10s\n", "ID", "Name", "Last Name", "Salary", "Sector");

		for (int i = 0; i < length; ++i)
		{
			if (list[i].isEmpty == FALSE)
			{
				show_employee(&list[i]);
			}
		}

		functionValue = 0;
	}

	return functionValue;
}



// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// FUNCIONES NECESARIAS
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


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



int enterEmployeeData(Employee* list, int len, int* id, int idCounter, char* name, char* lastName, float* salary, int* sector)
{
	int returnValue = -1;

	int index;
	index = getEmptySpaceInArray(list, len);

	if (index != -1)
	{
		printf("\n\nEntering a new employee... Please fill in the fields\n\n");

		*id = generateId(idCounter);
		getString(name, "Ingrese nombre: ", "Error. Ingrese nuevamente el nombre: ", 200);
		getString(lastName, "Ingrese apellido: ", "Error. Ingrese nuevamente el apellido: ", 200);
		*salary = getFloatInMinMaxRange("Ingrese salario: ", "Error. Ingrese nuevamente el salario: ", 0, 1000000);
		*sector = getIntInMinMaxRange("Ingrese sector: ", "Error. Ingrese nuevamente sector: ", 0, 100);

		returnValue = 0;
	}
	else
	{
		printf("Error. No empty space to enter an employee...\n");
	}

	return returnValue;
}


int generateId(int idCounter)
{
	int generatedId;

	if (idCounter == 0) {
		generatedId = ID;
	} else {
		generatedId = ID + idCounter;
	}

	return generatedId;
}



// MUESTRA UN EMPLEADO
void show_employee(Employee* list)
{
	printf("%-10d %-20s %-20s %-20.2f %-10d\n", (*list).id,(*list).name, (*list).lastName, (*list).salary, (*list).sector);
}




// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// FUNCIONES PARA MODIFICAR DATOS
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void modifyName(Employee* list, int len, int indexPosition)
{
	char newName[MAX_STRING_LENGHT];

	if (list != NULL)
	{
		getString(newName, "Ingrese nuevo nombre de empleado: ", "Error - motivo: [Nombre inválido]. Por favor ingrese otro nombre: ", MAX_STRING_LENGHT);
		strcpy(list[indexPosition].name, newName);
		printf("Has cambiado el nombre successfully!...\n\n");
	}
	else
	{
		printf("Error - No se ha podido cambiar el name...\n\n");
	}
}




void modifyLastName(Employee* list, int len, int indexPosition)
{
	char newLastName[MAX_STRING_LENGHT];

	if (list != NULL)
	{
		getString(newLastName, "Ingrese nuevo apellido de empleado: ", "Error - motivo: [Apellido inválido]. Por favor ingrese otro apellido: ", MAX_STRING_LENGHT);
		strcpy(list[indexPosition].lastName, newLastName);
		printf("Has cambiado el apellido successfully!...\n\n");
	}
	else
	{
		printf("Error - No se ha podido cambiar el apellido...\n\n");
	}
}




void modifySalary(Employee* list, int len, int indexPosition)
{
	float newSalary;

	if (list != NULL)
	{
		newSalary = getFloatInMinMaxRange("Ingrese nuevo salary de empleado: ", "Error - motivo: [Salary inválido]. Por favor ingrese otro salary: ", 0, 10000000);
		list[indexPosition].salary = newSalary;
		printf("Has cambiado el salary successfully!...\n\n");
	}
	else
	{
		printf("Error - No se ha podido cambiar el salary...\n\n");
	}
}



void modifySector(Employee* list, int len, int indexPosition)
{
	int newSector;

	if (list != NULL)
	{
		newSector = getIntInMinMaxRange("Ingrese nuevo sector de empleado: ", "Error - motivo: [Sector inválido]. Por favor ingrese otro sector: ", 1, 100);
		list[indexPosition].sector = newSector;
		printf("Has cambiado el sector successfully!...\n\n");
	}
	else
	{
		printf("Error - No se ha podido cambiar el sector...\n\n");
	}
}






























/*
int modifyName(Employee* list, int len, int id, int indexPosition)
{
	int functionValue = -1;
	char newName[MAX_STRING_LENGHT];

	if (list != NULL)
	{
		for (int i = 0; i < len; ++i)
		{
			if (id == list[i].id)
			{
				getString(newName, "Ingrese nuevo nombre de empleado: ", "Error - motivo: [Nombre inválido]. Por favor ingrese otro nombre", MAX_STRING_LENGHT);
				strcpy(list[i].name,newName);
			}
		}

		printf("Has cambiado el nombre successfully!...\n\n");
		functionValue = 0;
	}
	else
	{
		printf("Error - No se ha podido cambiar el name...\n\n");
	}



	return functionValue;
}
*/


























