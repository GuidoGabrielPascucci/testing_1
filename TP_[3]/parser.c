#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

#include <string.h>
#include "Inputs.h"





/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee) {

	int retorno = 0;
	char id[11];
	char nombre[128];
	char horasTrabajadas[11];
	char sueldo[11];

	if(pFile != NULL && pArrayListEmployee != NULL) {
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", id, nombre, horasTrabajadas, sueldo);

		while(!feof(pFile)) {
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", id, nombre, horasTrabajadas, sueldo);

			if(feof(pFile)) {
				break;
			}

			Employee *pEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
			ll_add(pArrayListEmployee, pEmployee);
		}

		retorno = 1;
	}


	return retorno;
}




/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee) {

	int retorno = 0;
	Employee *pEmployee = NULL;

	if(pFile != NULL && pArrayListEmployee != NULL) {

		while(!feof(pFile)) {
			pEmployee = employee_new();
			fread(pEmployee, sizeof(Employee), 1, pFile);

			if(feof(pFile)) {
				break;
			}

			ll_add(pArrayListEmployee, pEmployee);
			pEmployee = NULL;
		}

		retorno = 1;
	}


    return retorno;
}





int cargarDatosDeEmpleado(LinkedList* pArrayListEmployee, Employee *pEmployee) {

	int retorno = 0;

	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;


	if(pArrayListEmployee != NULL && pEmployee != NULL) {

		int ultimoIndexIngresado = ll_len(pArrayListEmployee);
		id = ultimoIndexIngresado + 1;

		getString(nombre, "\n\n\n-------------------------------------------------------------------------------------------------------------------\n"
						  "Ingrese nombre: ", "ERROR <<nombre invalido>> Por favor reingrese nombre: ", 128);


		getIntInMinMaxRange(&horasTrabajadas, "-------------------------------------------------------------------------------------------------------------------\n"
											  "Ingrese total de horas trabajadas: ", "ERROR <<entrada invalida>> Por favor reingrese las horas trabajadas:", 0, 100000);


		getIntInMinMaxRange(&sueldo, "-------------------------------------------------------------------------------------------------------------------\n"
									 "Ingrese sueldo: ", "ERROR <<numero invalido>> Por favor reingrese sueldo: ", 1, 1000000);


		printf("-------------------------------------------------------------------------------------------------------------------\n");

		employee_setId(pEmployee, id);
		employee_setNombre(pEmployee, nombre);
		employee_setHorasTrabajadas(pEmployee, horasTrabajadas);
		employee_setSueldo(pEmployee, sueldo);

		retorno = 1;
	}


	return retorno;
}





int editarEmpleado(Employee* pEmployee) {

	int retorno;
	int option;

	char nombre[128];
	int horasTrabajadas;
	int sueldo;


	getIntInMinMaxRange(&option, "\n\n\n-------------------------------------------------------------------------------------------------------------------\n"
								 "Menu Editar Empleado\n"
								 "-------------------------------------------------------------------------------------------------------------------\n"
								 "1. Modificar Nombre\n"
								 "2. Modificar Horas Trabajadas\n"
								 "3. Modificar Sueldo\n\n"
								 "4. Volver a la seleccion de empleado\n"
								 "5. Volver al menu principal\n"
								 "-------------------------------------------------------------------------------------------------------------------\n\n\n"
								 "Selecciona la modificacion que desees realizar: ",


								 "\n\n\nERROR! <<La opcion es invalida>>\n"
								 "-------------------------------------------------------------------------------------------------------------------\n"
								 "Menu Editar Empleado\n"
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
				getString(nombre, "\n\n-------------------------------------------------------------------------------------------------------------------\n"
								  "Ingrese nombre: ", "ERROR <<nombre invalido>> Por favor reingrese nombre: ", 128);

				employee_setNombre(pEmployee, nombre);
				retorno = 0;
				break;

			case 2:
				getIntInMinMaxRange(&horasTrabajadas, "\n\n-------------------------------------------------------------------------------------------------------------------\n"
													  "Ingrese total de horas trabajadas: ", "ERROR <<entrada invalida>> Por favor reingrese las horas trabajadas:", 0, 100000);

				employee_setHorasTrabajadas(pEmployee, horasTrabajadas);
				retorno = 0;
				break;

			case 3:
				getIntInMinMaxRange(&sueldo, "\n\n-------------------------------------------------------------------------------------------------------------------\n"
											 "Ingrese sueldo: ", "ERROR <<numero invalido>> Por favor reingrese sueldo: ", 1, 1000000);

				employee_setSueldo(pEmployee, sueldo);
				retorno = 0;
				break;

			case 4:
				retorno = 2;
				break;

			case 5:
				retorno = 3;
				break;
		}


	return retorno;
}





int removerEmpleado(Employee* pEmployee, LinkedList* pArrayListEmployee, int index) {

	int retorno;
	int option;


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
			if(confirmarRemoverEmpleado()) {
				employee_delete(pEmployee);
				ll_remove(pArrayListEmployee, index);
			retorno = 0;
			}
			else {
				retorno = 1;
			}
			break;

		case 2:
			retorno = 2;
			break;

		case 3:
			retorno = 3;
			break;
	}


	return retorno;
}





int confirmarRemoverEmpleado(void) {

	int option;
	getIntInMinMaxRange(&option, "\n\n-------------------------------------------------------------------------------------------------------------------\n"
								 "¿Confirma que desea borrar este empleado de la lista?\n"
								 "-------------------------------------------------------------------------------------------------------------------\n"
								 "1. SI, Eliminar Empleado\n"
								 "0. NO, Cancelar\n\n\n",

								 "\n\nERROR <<La opcion ingresada no es valida>>\n"
								 "Por favor reingrese una opcion...\n"
								 "-------------------------------------------------------------------------------------------------------------------\n"
								 "¿Confirma que desea borrar este empleado de la lista?\n"
								 "-------------------------------------------------------------------------------------------------------------------\n"
								 "1. SI, Eliminar Empleado\n"
								 "0. NO, Cancelar\n\n\n", 0, 1);

	return option;
}




int sortByID(Employee* pEmployeeA, Employee* pEmployeeB) {

	int employeeA;
	int employeeB;
	int retorno;

	employee_getId(pEmployeeA, &employeeA);
	employee_getId(pEmployeeB, &employeeB);

	if(employeeA > employeeB) {
		retorno = 1;
	}
	else if (employeeA < employeeB) {
		retorno = -1;
	}

	return retorno;
}




int sortByName(Employee* pEmployeeA, Employee* pEmployeeB) {

	char employeeA[128];
	char employeeB[128];
	int resultCmp;

	employee_getNombre(pEmployeeA, employeeA);
	employee_getNombre(pEmployeeB, employeeB);

	resultCmp = strcmp(employeeA, employeeB);


	return resultCmp;
}




int sortByHours(Employee* pEmployeeA, Employee* pEmployeeB) {

	int employeeA;
	int employeeB;
	int retorno;

	employee_getHorasTrabajadas(pEmployeeA, &employeeA);
	employee_getHorasTrabajadas(pEmployeeB, &employeeB);

	if(employeeA > employeeB) {
		retorno = 1;
	}
	else if (employeeA < employeeB) {
		retorno = -1;
	}

	return retorno;
}




int sortBySalary(Employee* pEmployeeA, Employee* pEmployeeB) {

	int employeeA;
	int employeeB;
	int retorno;

	employee_getSueldo(pEmployeeA, &employeeA);
	employee_getSueldo(pEmployeeB, &employeeB);

	if(employeeA > employeeB) {
		retorno = 1;
	}
	else if (employeeA < employeeB) {
		retorno = -1;
	}

	return retorno;
}






























