
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "remove_Employee.h"
#include "ArrayEmployees.h"
#include "Inputs.h"




void opcionBajaEmpleado(Employee* list, int len, int* contadorAltas)
{
	int idForSearch;
	int indexPositionForSearch;
	int seguirDandoDeBajaEmployees;


	if (list != NULL && len > -1)
	{
		do
		{
			printf("Contador altas: %d\n\n", (*contadorAltas));

			if (*contadorAltas > 0)
			{

				printf("CONTADOR DE ALTAS: %d\n\n", (*contadorAltas)); 		// SACAR DEL CODIGO. ONLY FOR TESTING !

				printEmployees(list, len); // IGUALAR A ALGO ?

				idForSearch = getNumeroMayorQueMinimo("************************************************************************************************\n\n"
													  "Remove Employee\n"
													  "Enter employee ID that you want to remove: \n\n"
													  "************************************************************************************************\n\n\n",

													  "************************************************************************************************\n\n"
													  "! Error - reason: [Invalid ID]\n"
													  "Please enter employee ID again: \n\n"
													  "************************************************************************************************\n\n\n", ID);


				indexPositionForSearch = findEmployeeById(list, len, idForSearch);

				if ( (indexPositionForSearch != -1) && (!removeEmployee(list, len, idForSearch)) && (verificarLosCambios(list, indexPositionForSearch)) )
				{
					(*contadorAltas)--;

					// SACAR DEL CODIGO. ONLY FOR TESTING !
					printf("Entro en el if de las 3 CONDICIONES\n"
							"Contador de Altas: %d", (*contadorAltas));
				}



				seguirDandoDeBajaEmployees = getIntInMinMaxRange("\n\n\n\n------------------------------------------------------------------------------------------------\n"
																 "Do you want to keep removing employees?\n"
																 "------------------------------------------------------------------------------------------------\n"
																 "1. Remove another employee\n"
																 "2. Back to Main Menu\n\n\n\n",

																 "! Error - reason: [Invalid option]\n"
																 "Please enter an option again\n"
																 "------------------------------------------------------------------------------------------------\n"
																 "Do you want to keep removing employees??"
																 "------------------------------------------------------------------------------------------------\n\n"
																 "1. Remove another employee\n"
																 "2. Back to Main Menu\n\n\n\n", 1, 2);
			}
			else
			{
				printf("\n------------------------------------------------------------------------------------------------\n"
						"Error. Do not allowed modifications - reason: [No employee loaded in system]\n\n"
						"You will be directed to Main Menu...\n"
						"------------------------------------------------------------------------------------------------\n\n\n\n");
				system("pause");
				break;
			}

		} while (seguirDandoDeBajaEmployees != 2);

	}
	else
	{
		printf("\n------------------------------------------------------------------------------------------------\n"
			   "Error - reason: [Invalid length or NULL pointer]\n\n\n"
			   "------------------------------------------------------------------------------------------------\n\n\n\n");
	}

}





// VERIFICA LOS CAMBIOS ANTES DE EFECTUAR DEFINITIVAMENTE LA BAJA
int verificarLosCambios(Employee* list, int index)
{
	int verificacion;
	verificacion = getIntInMinMaxRange("\n\n************************************************************************************************\n\n"
										"Security Check\n\n"
										"************************************************************************************************\n\n"
										"Confirma que desea eliminar este empleado de la nómina?\n"
										"1. Remove Employee\n"
										"0. Undo changes\n\n",

										"\n\n\n¡Error de confirmación! motivo: [Has ingresado una opción inválida]\n"
										"Por favor reingrese un número\n\n"
										"************************************************************************************************\n"
										"Security Check\n"
										"************************************************************************************************\n"
										"Confirma que desea eliminar este empleado de la nómina?\n\n"
										"1. Remove Employee\n"
										"0. Undo changes\n\n", 0, 1);

	if (verificacion)
	{
		printf("\n\n________________________________________________________________________________________________\n\n"
				"Employee removed!...\n"
				"________________________________________________________________________________________________\n\n\n");
	}
	else
	{
		list[index].isEmpty = FALSE;
		printf("\n\n________________________________________________________________________________________________\n\n"
				"Changes have been restored.\n"
				"________________________________________________________________________________________________\n\n\n");
	}

	system("pause");

	return verificacion;
}



















