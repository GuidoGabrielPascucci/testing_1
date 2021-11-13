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

int controller_editEmployee(LinkedList* pArrayListEmployee) {

	int retorno = -1;
	int selectedID;
	int index = -1;
	Employee *pEmployee = NULL;

	if(pArrayListEmployee != NULL) {

		do{
			controller_ListEmployee(pArrayListEmployee);

			getIntHigherThan(&selectedID, "\n\n-------------------------------------------------------------------------------------------------------------------\n"
										  "Ingrese el ID del empleado que desee modificar: ",

										  "\n\n-------------------------------------------------------------------------------------------------------------------\n"
										  "ERROR <<Entrada invalida - El ID debe ser un numero entero mayor a cero>>\n"
										  "Por favor reingrese el ID del empleado que desee modificar: ", 0);


			for (int i = 0; i < ll_len(pArrayListEmployee); ++i) {

				pEmployee = (Employee*) ll_get(pArrayListEmployee, i);

				if(selectedID == pEmployee->id) {
					index = i;
					break;
				}
			}


			if(index == -1) {
				printf("\nERROR <<ID no encontrado>>\n"
						"El ID seleccionado no pertenece a ningun empleado cargado en la lista\n\n");
				system("pause");
			}

		} while(index == -1);


		retorno = editarEmpleado(pEmployee);
	}




	return retorno;
}
















/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee) {

	int retorno = -1;
	int selectedID;
	int index = -1;
	Employee *pEmployee = NULL;


	if(pArrayListEmployee != NULL) {

		do{
			controller_ListEmployee(pArrayListEmployee);

			getIntHigherThan(&selectedID, "\n\n-------------------------------------------------------------------------------------------------------------------\n"
										  "Ingrese el ID del empleado que desee remover de la lista: ",

										  "\n\n-------------------------------------------------------------------------------------------------------------------\n"
										  "ERROR <<Entrada invalida - El ID debe ser un numero entero mayor a cero>>\n"
										  "Por favor reingrese el ID del empleado que desee remover de la lista: ", 0);


			for (int i = 0; i < ll_len(pArrayListEmployee); ++i) {

				pEmployee = (Employee*) ll_get(pArrayListEmployee, i);

				if(selectedID == pEmployee->id) {
					index = i;
					break;
				}
			}

			if(index == -1) {
				printf("\nERROR <<ID no encontrado>>\n"
						"El ID seleccionado no pertenece a ningun empleado cargado en la lista\n\n");
				system("pause");
			}

		} while(index == -1);


		retorno = removerEmpleado(pEmployee, pArrayListEmployee, index);
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

		pEmployee = (Employee*) ll_get(pArrayListEmployee, i);

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
	int option;
	int criterioDeOrdenamiento;

	int (*pSortByID)() = sortByID;
	int (*pSortByName)() = sortByName;
	int (*pSortByHours)() = sortByHours;
	int (*pSortBySalary)() = sortBySalary;


	if(pArrayListEmployee != NULL) {


		getIntInMinMaxRange(&option, "\n\n\nSeleccione la opcion de ordenamiento que desee:\n"
									 	   "-------------------------------------------------------------------------------------------------------------------\n"
									 	   "1. ID\n"
									 	   "2. Nombre\n"
									 	   "3. Horas Trabajadas\n"
									 	   "4. Sueldo\n\n\n",


									 "\n\n\nERROR <<Opcion no valida>>\n"
										   "Seleccione la opcion de ordenamiento que desee:\n"
										   "-------------------------------------------------------------------------------------------------------------------\n"
										   "1. ID\n"
										   "2. Nombre\n"
										   "3. Horas Trabajadas\n"
										   "4. Sueldo\n\n\n", 1, 4);


		getIntInMinMaxRange(&criterioDeOrdenamiento, "\nSeleccione el criterio de ordenamiento:\n"
													   "-------------------------------------------------------------------------------------------------------------------\n"
													   "0. Descendente\n"
													   "1. Ascendente\n",

													 "\nERROR <<Opcion no valida>>\n"
													   "Seleccione el criterio de ordenamiento:\n"
													   "-------------------------------------------------------------------------------------------------------------------\n"
													   "0. Descendente\n"
													   "1. Ascendente\n", 0, 1);




		switch(option) {
			case 1:
				ll_sort(pArrayListEmployee, pSortByID, criterioDeOrdenamiento);
				break;

			case 2:
				ll_sort(pArrayListEmployee, pSortByName, criterioDeOrdenamiento);
				break;

			case 3:
				ll_sort(pArrayListEmployee, pSortByHours, criterioDeOrdenamiento);
				break;

			case 4:
				ll_sort(pArrayListEmployee, pSortBySalary, criterioDeOrdenamiento);
				break;
		}

		retorno = 1;
	}


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



