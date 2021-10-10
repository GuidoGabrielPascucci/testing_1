#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Menu.h"
#include "ArrayEmployees.h"
#include "Inputs.h"
#include "remove_Employee.h"



void menuDeOpciones(Employee* list, int length)
{
	/*
	int idForSearch;
	int indexPositionForSearch;
	int subMenuOption;
	int idCounter = 0;
	int seguirIngresandoAlta;
	int order;
	int resultadoFuncionSort;
	*/

	int contadorAltas = 0;
	int option;

	do
		{
			option = getIntInMinMaxRange("\n_______________________________________________________________________________________________\n\n\n"
										 "MAIN MENU\n\n"
										 "_______________________________________________________________________________________________\n\n"
										 "Enter an option:\n"
										 "------------------------------------------------------------------------------------------------\n\n"
										 "1. ALTA\n"
										 "2. MODIFICAR\n"
										 "3. BAJA\n"
										 "4. INFORMAR\n"
										 "5. EXIT\n\n"
										 "_______________________________________________________________________________________________\n\n",

										 "\nError: entrada no válida. Reingrese opcion del menu:\n"
										 "_______________________________________________________________________________________________\n\n"
										 "1. ALTA\n"
										 "2. MODIFICAR\n"
										 "3. BAJA\n"
										 "4. INFORMAR\n"
										 "5. EXIT\n\n\n", 1, 5);


			switch (option)
			{
				case 1:
					// ALTA EMPLEADO
					opcionDarDeAltaEmpleado(list, length, &contadorAltas);

					printf("CONTADOR DE ALTAS: %d", contadorAltas);
					break;

				case 2:
					// MODIFICAR DATOS DE EMPLEADO

					subMenuModificaciones(list, length, contadorAltas);

					printf("CONTADOR DE ALTAS: %d", contadorAltas);
					break;

				case 3:
					// BAJA DE EMPLEADO

					opcionBajaEmpleado(list, length, &contadorAltas);

					printf("CONTADOR DE ALTAS: %d", contadorAltas);
					break;

				case 4:
					// INFORMAR

					opcionInformar(list, length, contadorAltas);

					printf("CONTADOR DE ALTAS: %d", contadorAltas);
					break;

				case 5:
					// Exit Program
					break;
			}



		} while (option != 5);

}








































