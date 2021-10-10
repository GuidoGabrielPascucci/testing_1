
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inform_Employee.h"
#include "ArrayEmployees.h"
#include "Inputs.h"



void opcionInformar(Employee* list, int length, int contadorAltas)
{
	// INFORMAR:
	// 1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
	// 2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
	int order;

	if (contadorAltas > 0)
	{
		order = getIntInMinMaxRange("\nEnter order:\n"
									"0. DOWN\n"
									"1. UP\n\n",

									"\nError - reason: [Invalid order]\n"
									"Please enter order again:\n"
									"0. DOWN\n"
									"1. UP\n\n", 0, 1);


		if ( !sortEmployees(list, length, order) )
		{
			printEmployees(list, length);
			printf("\n\n\n\n\n");
		}
		else
		{
			printf("No se pudo mostrar el listado [Datos inválidos]\n\n");
		}

	}
	else
	{
		printf("\n------------------------------------------------------------------------------------------------\n"
				"Error. Do not allowed modifications - reason: [No employee loaded in system]\n\n"
				"You will be directed to Main Menu...\n"
				"------------------------------------------------------------------------------------------------\n\n\n\n");
	}
}






void sortDescendente(Employee* list, int len)
{
	int auxId;
	char auxName[MAX_STRING_LENGHT];
	char auxLastName[MAX_STRING_LENGHT];
	float auxSalary;
	int auxSector;

	int flagSwap;
	int nuevoLimite = len - 1;

	do
	{
		flagSwap = 0;

		for (int i = 0; i < nuevoLimite; ++i)
		{
			if ( (list[i].isEmpty == FALSE && list[i+1].isEmpty == FALSE) && (stricmp(list[i].lastName, list[i+1].lastName) == -1) )
			{
				// SWAP ID:
				auxId = list[i].id;
				list[i].id = list[i+1].id;
				list[i+1].id = auxId;

				// SWAP Name:
				strcpy(auxName, list[i].name);
				strcpy(list[i].name, list[i+1].name);
				strcpy(list[i+1].name, auxName);

				// SWAP Last Name:
				strcpy(auxLastName, list[i].lastName);
				strcpy(list[i].lastName, list[i+1].lastName);
				strcpy(list[i+1].lastName, auxLastName);

				// SWAP Salary:
				auxSalary = list[i].salary;
				list[i].salary = list[i+1].salary;
				list[i+1].salary = auxSalary;

				// SWAP Sector:
				auxSector = list[i].sector;
				list[i].sector = list[i+1].sector;
				list[i+1].sector = auxSector;

				flagSwap = 1;
			}
			else
			{
				if ( (list[i].isEmpty == FALSE && list[i+1].isEmpty == FALSE) && (stricmp(list[i].lastName, list[i+1].lastName) == 0) && (list[i].sector < list[i+1].sector) )
				{
					// SWAP ID:
					auxId = list[i].id;
					list[i].id = list[i+1].id;
					list[i+1].id = auxId;

					// SWAP Name:
					strcpy(auxName, list[i].name);
					strcpy(list[i].name, list[i+1].name);
					strcpy(list[i+1].name, auxName);

					// SWAP Salary:
					auxSalary = list[i].salary;
					list[i].salary = list[i+1].salary;
					list[i+1].salary = auxSalary;

					// SWAP Sector:
					auxSector = list[i].sector;
					list[i].sector = list[i+1].sector;
					list[i+1].sector = auxSector;

					flagSwap = 1;
				}
			}
		}

		nuevoLimite--;


	} while(flagSwap);

}



void sortAscendente(Employee* list, int len)
{
	int auxId;
	char auxName[MAX_STRING_LENGHT];
	char auxLastName[MAX_STRING_LENGHT];
	float auxSalary;
	int auxSector;

	int flagSwap;
	int nuevoLimite = len - 1;


	do
	{
		flagSwap = 0;

		for (int i = 0; i < nuevoLimite; ++i)
		{
			if ( (list[i].isEmpty == FALSE && list[i+1].isEmpty == FALSE) && (stricmp(list[i].lastName, list[i+1].lastName) == 1) )
			{
				// SWAP ID:
				auxId = list[i].id;
				list[i].id = list[i+1].id;
				list[i+1].id = auxId;

				// SWAP Name:
				strcpy(auxName, list[i].name);
				strcpy(list[i].name, list[i+1].name);
				strcpy(list[i+1].name, auxName);

				// SWAP Last Name:
				strcpy(auxLastName, list[i].lastName);
				strcpy(list[i].lastName, list[i+1].lastName);
				strcpy(list[i+1].lastName, auxLastName);

				// SWAP Salary:
				auxSalary = list[i].salary;
				list[i].salary = list[i+1].salary;
				list[i+1].salary = auxSalary;

				// SWAP Sector:
				auxSector = list[i].sector;
				list[i].sector = list[i+1].sector;
				list[i+1].sector = auxSector;

				flagSwap = 1;
			}
			else
			{
				if ( (list[i].isEmpty == FALSE && list[i+1].isEmpty == FALSE) &&  (stricmp(list[i].lastName, list[i+1].lastName) == 0) && (list[i].sector > list[i+1].sector) )
				{
					// SWAP ID:
					auxId = list[i].id;
					list[i].id = list[i+1].id;
					list[i+1].id = auxId;

					// SWAP Name:
					strcpy(auxName, list[i].name);
					strcpy(list[i].name, list[i+1].name);
					strcpy(list[i+1].name, auxName);

					// SWAP Salary:
					auxSalary = list[i].salary;
					list[i].salary = list[i+1].salary;
					list[i+1].salary = auxSalary;

					// SWAP Sector:
					auxSector = list[i].sector;
					list[i].sector = list[i+1].sector;
					list[i+1].sector = auxSector;

					flagSwap = 1;
				}
			}
		}

		nuevoLimite--;

	} while(flagSwap);

}






