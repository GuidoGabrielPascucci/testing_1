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
		/// PIDO LOS DATOS
		int ultimoIndexIngresado = ll_len(pArrayListEmployee);
		id = ultimoIndexIngresado + 1;

		getString(nombre, "\n\n\nIngrese nombre: ", "ERROR <<nombre invalido>> Por favor reingrese nombre: ", 128);
		getIntInMinMaxRange(&horasTrabajadas, "Ingrese total de horas trabajadas: ", "ERROR <<entrada invalida>> Por favor reingrese las horas trabajadas:", 0, 1000);
		getIntInMinMaxRange(&sueldo, "Ingrese sueldo: ", "ERROR <<numero invalido>> Por favor reingrese sueldo: ", 1, 1000000);

		/// SETTEO LOS DATOS EN EMPLOYEE STRUCT
		employee_setId(pEmployee, id);
		employee_setNombre(pEmployee, nombre);
		employee_setHorasTrabajadas(pEmployee, horasTrabajadas);
		employee_setSueldo(pEmployee, sueldo);

		retorno = 1;
	}


	return retorno;
}





int confirmarRemoverEmpleado(void) {

	int option;
	getIntInMinMaxRange(&option, "\n\n-------------------------------------------------------------------------------------------------------------------\n"
								 "¿Confirma que desea borrar este empleado de la lista?\n"
								 "-------------------------------------------------------------------------------------------------------------------\n"
								 "1. Eliminar Empleado\n"
								 "0. Cancelar\n\n\n",

								 "\n\nERROR <<La opcion ingresada no es valida>>\n"
								 "Por favor reingrese una opcion...\n"
								 "-------------------------------------------------------------------------------------------------------------------\n"
								 "¿Confirma que desea borrar este empleado de la lista?\n"
								 "-------------------------------------------------------------------------------------------------------------------\n"
								 "1. Eliminar Empleado\n"
								 "0. Cancelar\n\n\n", 0, 1);

	return option;
}





/*
int generarID(int contadorID) {

	int idGenerador;

	if(contadorID == 0) {
		idGenerador = ID;
	}
	else {
		idGenerador = ID + contadorID;
	}

	return idGenerador;
}
*/
