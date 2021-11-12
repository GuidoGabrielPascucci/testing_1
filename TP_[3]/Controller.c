#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"

#include "Inputs.h"

#define ID 1001
#define SIZE_NAME 128
#define SIZE_INT 11


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee) {

	int retorno = 0;
	FILE *pFile = fopen(path, "r");
	retorno = parser_EmployeeFromText(pFile, pArrayListEmployee);
	fclose(pFile);

    return retorno;
}




/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee) {

	int retorno = 0;
	FILE *pFile = fopen(path, "rb");
	retorno = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
	fclose(pFile);

    return retorno;
}




/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee) {

	int retorno = 0;
	Employee *pEmployee = NULL;
	pEmployee = employee_new();

	retorno = cargarDatosDeEmpleado(pArrayListEmployee, pEmployee);
	ll_add(pArrayListEmployee, pEmployee);

    return retorno;
}







/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*
int controller_editEmployee(LinkedList* pArrayListEmployee) {

	int retorno = 0;
	int option;
	int selectedID;
	Employee *pEmployee = NULL;


	/// MUESTRO LISTA DE EMPLEADOS PARA QUE USUARIO ELIJA ID A MODIFICAR
	controller_ListEmployee(pArrayListEmployee);

	/// GUARDO ID SELECCIONADO
	getIntHigherThan(&selectedID, "Ingrese el ID del empleado que desee modificar: ",

								  "ERROR <<Entrada invalida - El ID debe ser un numero entero mayor a cero>>\n"
								  "Por favor reingrese el ID del empleado que desee modificar: ", 1);



	for (int i = 0; i < ll_len(pArrayListEmployee); ++i) {

		if () {

		}
	}


	/// pEmployee = ll_get(pArrayListEmployee, selectedID);


	if(pEmployee != NULL) {

	}
	else {
		printf("\nERROR <<ID no encontrado>>");
	}



	employee_getId(pArrayListEmployee, selectedID);


	do{

		getIntInMinMaxRange(&option, "-------------------------------------------------------------------------------------------------------------------\n"
									  "Editar Empleado\n"
									  "-------------------------------------------------------------------------------------------------------------------\n"
									  "1. Modificar Nombre\n"
									  "2. Modificar Horas Trabajadas\n"
									  "3. Modificar Sueldo\n\n"
									  "4. Volver a la seleccion de empleado\n"
									  "5. Volver al menu principal\n"
									  "-------------------------------------------------------------------------------------------------------------------\n\n\n"
									  "Selecciona la modificacion que desees realizar: ",

									  "ERROR! <<La opcion es invalida>>\n"
									  "-------------------------------------------------------------------------------------------------------------------\n"
									  "Editar Empleado\n"
									  "-------------------------------------------------------------------------------------------------------------------\n"
									  "1. Modificar Nombre\n"
									  "2. Modificar Horas Trabajadas\n"
									  "3. Modificar Sueldo\n\n"
									  "4. Volver a la seleccion de empleado\n"
									  "5. Volver al menu principal\n"
									  "-------------------------------------------------------------------------------------------------------------------\n\n\n"
									  "Vuelve a seleccionar la modificacion que desees realizar: ", 1, 5);


		switch(option) {

			case 1:
				/// funcion modificar nombre
				break;

			case 2:
				/// funcion modificar horas trabajadas
				break;

			case 3:
				/// funcion modificar sueldo
				break;
		}

	} while(option != 4 && option != 5);



	return retorno;
}
*/



/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee) {

	int retorno = -1;
	int option;
	int selectedID;
	//Employee *pEmployee = NULL;

	if(pArrayListEmployee != NULL) {

		/// MUESTRO LISTA DE EMPLEADOS PARA QUE USUARIO ELIJA ID A BORRAR
		controller_ListEmployee(pArrayListEmployee);

		/// GUARDO ID SELECCIONADO
		getIntHigherThan(&selectedID, "\n\n-------------------------------------------------------------------------------------------------------------------\n"
									  "Ingrese el ID del empleado que desee remover de la lista: ",

									  "\n\n-------------------------------------------------------------------------------------------------------------------\n"
									  "ERROR <<Entrada invalida - El ID debe ser un numero entero mayor a cero>>\n"
									  "Por favor reingrese el ID del empleado que desee remover de la lista: ", 1);


		/*
		for (int i = 0; i < ll_len(pArrayListEmployee); ++i) {
		}
		/// pEmployee = ll_get(pArrayListEmployee, selectedID);
		if(pEmployee != NULL) {

		}
		else {
			printf("\nERROR <<ID no encontrado>>");
		}
		employee_getId(pArrayListEmployee, selectedID);
		 */


			getIntInMinMaxRange(&option, "\n\n\n-------------------------------------------------------------------------------------------------------------------\n"
										 "Menu Remover Empleado\n"
										 "-------------------------------------------------------------------------------------------------------------------\n"
										 "1. Remover Empleado de la lista\n\n"
										 "2. Volver a la seleccion de empleado\n"
										 "3. Volver al menu principal\n"
										 "-------------------------------------------------------------------------------------------------------------------\n\n\n"
										 "Selecciona la opcion que desees realizar: ",


										 "\n\n\nERROR! <<La opcion ingresada no es valida>>\n"
										 "-------------------------------------------------------------------------------------------------------------------\n"
										 "Menu Remover Empleado\n"
										 "-------------------------------------------------------------------------------------------------------------------\n"
										 "1. Remover Empleado de la lista\n\n"
										 "2. Volver a la seleccion de empleado\n"
										 "3. Volver al menu principal\n"
										 "-------------------------------------------------------------------------------------------------------------------\n\n\n"
										 "Selecciona nuevamente la opcion que desees realizar: ", 1, 3);


			switch(option) {
				case 1:
					/// REMOVER EMPLEADO
					if(confirmarRemoverEmpleado()) {
					/// codigo para borrar empleado
					///
					///
					///
					retorno = 0;
					}
					else {
						retorno = 1;
					}
					break;

				case 2:
					/// opcion 2 - Volver a la seleccion de empleado
					retorno = 2;
					break;

				case 3:
					/// opcion 3 - Volver al menu principal
					retorno = 3;
					break;
			}
	}


	return retorno;
}





/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee) {

	Employee *pEmployee = NULL;
	int retorno = 0;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	printf("\n\n\n\nLISTA DE EMPLEADOS\n"
			"-------------------------------------------------------------------------------------------------------------------\n"
			"%-20s %-30s %-35s %-10s", "ID", "Nombre", "Horas Trabajadas", "Sueldo\n"
			"-------------------------------------------------------------------------------------------------------------------\n" );

	for (int i = 0; i < ll_len(pArrayListEmployee); ++i) {

		pEmployee = ll_get(pArrayListEmployee, i);

		employee_getId(pEmployee, &id);
		employee_getNombre(pEmployee, nombre);
		employee_getHorasTrabajadas(pEmployee, &horasTrabajadas);
		employee_getSueldo(pEmployee, &sueldo);

		pEmployee = NULL;
		printf("%-20d %-30s %-35d %-10d\n", id, nombre, horasTrabajadas, sueldo);
	}


    return retorno;
}




/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee) {

	int retorno = 0;






	return retorno;
}




/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee) {

	int retorno = 0;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	Employee *pEmployee = NULL;
	FILE *pFile = fopen(path, "w");

	if(pFile != NULL && pArrayListEmployee != NULL) {

		fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");

		for (int i = 0; i < ll_len(pArrayListEmployee); ++i) {
			pEmployee = (Employee*) ll_get(pArrayListEmployee, i);

			employee_getId(pEmployee, &id);
			employee_getNombre(pEmployee, nombre);
			employee_getHorasTrabajadas(pEmployee, &horasTrabajadas);
			employee_getSueldo(pEmployee, &sueldo);

			fprintf(pFile, "%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
			pEmployee = NULL;
		}

		fclose(pFile);
		retorno = 1;
	}


    return retorno;
}




/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee) {

	int retorno = 0;
	Employee *pEmployee = NULL;
	FILE *pFile = fopen(path, "wb");

	if(pFile != NULL && pArrayListEmployee != NULL) {

		for (int i = 0; i < ll_len(pArrayListEmployee); ++i) {
			pEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			fwrite(pEmployee, sizeof(Employee), 1, pFile);
			pEmployee = NULL;
		}

		fclose(pFile);
		retorno = 1;
	}


    return retorno;
}



