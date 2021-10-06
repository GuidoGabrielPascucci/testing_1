// TP 2

// Una empresa requiere un sistema para administrar su nómina de empleados. Se sabe que
//dicha nómina bajo ninguna circunstancia superara los 1000 empleados.

/*
El sistema deberá tener el siguiente menú de opciones:
1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
de Id. El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Salario o Sector.
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:
1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.

NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de algún empleado.
*/
#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "Inputs.h"
#include "Validaciones.h"


int main(void)
{
	setbuf(stdout, NULL);
	printf("WELCOME!\n\n");

	Employee arrayEmployees[MAX_EMPLOYEES];

	// variables auxiliares
	int idResult;
	char cadenaNombre[MAX_STRING_LENGHT];
	char cadenaApellido[MAX_STRING_LENGHT];
	float salario;
	int sectorCopy;
	//

	initEmployees(arrayEmployees, MAX_EMPLOYEES);

	int idForSearch;
	int indexPositionForSearch;
	int contadorAltas = 0;
	int idCounter = 0;
	int subMenuOption;
	int option;

	do
	{
		option = getIntInMinMaxRange("\nIngrese la opcion que desee:\n"
									 "-----------------------------------------------------------------------------------------------\n"
									 "1. ALTA\n"
									 "2. MODIFICAR\n"
									 "3. BAJA\n"
									 "4. INFORMAR\n"
									 "5. EXIT\n",
									 "\nError: entrada no válida. Reingrese opcion del menu:\n"
									 "-----------------------------------------------------------------------------------------------\n"
									 "1. ALTA\n"
									 "2. MODIFICAR\n"
									 "3. BAJA\n"
									 "4. INFORMAR\n"
									 "5. EXIT\n", 1, 5);

		switch (option)
		{
			case 1:
				if (!enterEmployeeData(arrayEmployees, MAX_EMPLOYEES, &idResult, idCounter, cadenaNombre, cadenaApellido, &salario, &sectorCopy))
				{
					addEmployee(arrayEmployees, MAX_EMPLOYEES, idResult, cadenaNombre, cadenaApellido, salario, sectorCopy);
					idCounter++;
				}

				contadorAltas++;
				system("pause");
				break;

			case 2:
				if (contadorAltas > 0)
				{
					printEmployees(arrayEmployees, MAX_EMPLOYEES);
					idForSearch = getNumeroMayorQueMinimo("\n\nIngrese un ID para comenzar la búsqueda: \n", "Error - motivo: [Numero inválido]\nPor favor ingrese nuevamente un ID para comenzar la búsqueda: ", ID);
					indexPositionForSearch = findEmployeeById(arrayEmployees, MAX_EMPLOYEES, idForSearch);

					if (indexPositionForSearch != -1)
					{
						do {
							subMenuOption = getIntInMinMaxRange("\n\nMenu Modificaciones\n"
																"-------------------------------------\n"
																"Qué desea modificar?\n\n"
																"1. Employee Name\n"
																"2. Employee Last Name\n"
																"3. Employee Salary\n"
																"4. Employee Sector\n"
																"5. Volver al Main Menu\n"
																"-------------------------------------\n",
																"\n\nError - motivo: [Número inválido]\n"
																"Por favor ingrese nuevamente una opción.\n"
																"Menu Modificaciones\n"
																"-------------------------------------\n"
																"Qué desea modificar?\n"
																"1. Employee Name\n"
																"2. Employee Last Name\n"
																"3. Employee Salary\n"
																"4. Employee Sector\n"
																"5. Volver al Main Menu\n"
																"-------------------------------------\n\n", 1, 5);

							switch(subMenuOption)
							{
								case 1:
									modifyName(arrayEmployees, MAX_EMPLOYEES, indexPositionForSearch);
									break;

								case 2:
									modifyLastName(arrayEmployees, MAX_EMPLOYEES, indexPositionForSearch);
									break;

								case 3:
									modifySalary(arrayEmployees, MAX_EMPLOYEES, indexPositionForSearch);
									break;

								case 4:
									modifySector(arrayEmployees, MAX_EMPLOYEES, indexPositionForSearch);
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
					printf("No hay empleados para mostrar");
				}
				break;

			case 3:
				// BAJA
				if (contadorAltas > 0)
				{

				}
				else
				{
					printf("No hay empleados para mostrar");
				}
				break;

			case 4:
				// INFORMAR:
				// 1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
				// 2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
				printEmployees(arrayEmployees, MAX_EMPLOYEES);
				break;

			case 5:
				// Exit Program
				printf("\n\nThank you for being there! Bye");
				break;
		}

	} while (option != 5);


	return EXIT_SUCCESS;
}




