#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "Inputs.h"





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
int initEmployees(Employee* list, int len) {
	int functionReturn = -1;

	if (list != NULL || len < -1) {			// LEN < -1 ???
		for (int i = 0; i < len; ++i) {
			list[i].isEmpty = TRUE;
		}
		functionReturn = 0;
	} else {
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


int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector) { 			// PARA QUE TANTOS PARAMETROS ??????????




	int functionReturn = -1;


	int index = employee_searchForEmptySpace(list, len);

	if(index != -1) {
		printf("Entering a new employee...\n");
		enter_employee(list);
		printf("Employee added!\n");

		//employee_enterEmployee(list, index);
		functionReturn = 0;
	} else {
		printf("Error. No empty space to enter an employee...\n");
	}

	return functionReturn;
}



/*
int addEmployee(Employee list[], int len) { // ESTA FUNCION NO VA.
	int functionReturn = -1;
	int index = employee_searchForEmptySpace(list, len);

	if(index != -1) {
		printf("Entering a new employee...\n");
		employee_enterEmployee(list, index);
		printf("Employee added!\n");
		functionReturn = 0;
	} else {
		printf("Error. No empty space to enter an employee...\n");
	}

	return functionReturn;
}
*/



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
/*
int findEmployeeById(Employee* list, int len, int id) {

	int functionReturn = -1;


	functionReturn = 0;

	return NULL;
}
*/



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
int printEmployees(Employee* list, int length) {
	 return 0;
}




// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



// FUNCION PARA TESTEO

void this_isHardCode(Employee* list, int len) {
	int ids[] = {1000, 1001, 1002};
	char name[][51] = {"Jose", "Pepe", "Lelo"};
	char lastName[][51] = {"Perreke", "Perreka", "Perroski"};
	float salary[] = {15680.24, 13512.56, 19845.74};
	int sector[] = {1, 3, 8};

	for (int i = 0; i<len; i++) {
		list[i].id = ids[i];
		strcpy(list[i].name, name[i]);
		strcpy(list[i].lastName, lastName[i]);
		list[i].salary = salary[i];
		list[i].sector = sector[i];
		list[i].isEmpty = FALSE;
	}
}



// INGRESA UN EMPLEADO
void enter_employee(Employee* list, int len) {
	for (int i = 0; i < len; i++) {
		if (employee_searchForEmptySpace(list, len) != -1) {
			get_string((*list).name, "Ingrese nombre: ", "Error. Ingrese nuevamente el nombre: ", 250);
			get_string((*list).lastName, "Ingrese apellido: ", "Error. Ingrese nuevamente el apellido: ", 250);
			(*list).salary = get_float("Ingrese salario: ", "Error. Ingrese nuevamente el salario: ", 0, 500000);
			(*list).sector = get_integer("Ingrese sector: ", "Error. Ingrese nuevamente sector: ", 0, 100);
			get_id(list, len);
		}
		else
		{
			printf("Error. No empty space to enter an employee...\n");
		}
	}
}


// MUESTRA UN EMPLEADO
void show_employee(Employee* list) {
	printf("ID: %d\n"
			"Name: %s\n"
			"Last name: %s\n"
			"Salary: %.2f\n"
			"Sector: %d\n\n", (*list).id,(*list).name, (*list).lastName, (*list).salary, (*list).sector);
}


// MUESTRA TODOS LOS EMPLEADOS ---> ES LA FUNCION PRINTEMPLOYEE.
void show_allEmployees(Employee* list, int len) {
	for (int i = 0; i < len; ++i) {
		if (list[i].isEmpty == FALSE) {
			show_employee(&list[i]);
		}
	}
}

// COMO GENERAR ID AUTOMATICO E INCREMENTAL
void get_id(Employee* list, int len) {
	int id = 1000;
	int contadorEmpleados = 0;
	for (int i = 0; i < len; ++i)
	{
		if (contadorEmpleados == 0 && list[i].isEmpty == TRUE)
		{
			list[i].id = id;
			list[i].isEmpty = FALSE;
			break;
		}

		else if (contadorEmpleados > 0 && list[i].isEmpty == TRUE)
		{
			id += 1;
			list[i].id = id;
			list[i].isEmpty = FALSE;
		}
		contadorEmpleados++;
	}
}


// BUSCA ESPACIO LIBRE EN EL ARRAY ---> DEVUELVE EL SUBINDICE (INDEX)
int employee_searchForEmptySpace(Employee* list, int len) {
	int index = -1;
	for (int i = 0; i < len; ++i) {
		if (list[i].isEmpty == TRUE) {
			index = i;
			break;
		}
	}

	return index;
}




/*
void employee_enterEmployee(Employee* list, int i) {
	list[i].id = get_integer("Enter employee ID: ", "Error. Please enter employee ID again: ", 0, 1000); 					// VALORES MINIMO Y MAXIMO ?????????????? MAL. EL ID SE CALCULA AUTOMATICAMENTE!!!!
	get_string(list[i].name, "Enter employee name: ", "Error. Please enter employee name again: ", MAXSTRINGLENGHT);
	get_string(list[i].lastName, "Enter employee last name: ", "Error. Please enter employee last name again: ", MAXSTRINGLENGHT);
	list[i].salary = get_float("Enter employee salary: ", "Error. Please enter employee salary again: ", 0, 1000); 			// VALORES MINIMO Y MAXIMO ??????????????
	list[i].sector = get_integer("Enter employee sector: ", "Error. Please enter employee sector again: ", 0, 1000);		 // VALORES MINIMO Y MAXIMO ??????????????
	list[i].isEmpty = FALSE;
}
*/



/*
void employee_getInformation(Employee* list, char* name, char* lastName, float* salary, int* sector) {
	get_string(name, "Enter employee name: ", "Error. Please enter employee name again: ", MAXSTRINGLENGHT);
	get_string(lastName, "Enter employee last name: ", "Error. Please enter employee last name again: ", MAXSTRINGLENGHT);
	*salary = get_float("Enter employee salary: ", "Error. Please enter employee salary again: ", 0, 1000); 					// VALORES MINIMO Y MAXIMO PARA SALARY ??????
	*sector = get_integer("Enter employee sector: ", "Error. Please enter employee sector again: ", 0, 1000);
*/

/*
	char string[MAXSTRINGLENGHT];
	char string2[MAXSTRINGLENGHT];
	get_string(string, "Enter employee name: ", "Error. Please enter employee name again: ", MAXSTRINGLENGHT);
	get_string(string2, "Enter employee last name: ", "Error. Please enter employee last name again: ", MAXSTRINGLENGHT);
	*name = *string;
	*lastName = *string2;
	*salary = get_float("Enter employee salary: ", "Error. Please enter employee salary again: ", 0, 1000); 					// VALORES MINIMO Y MAXIMO PARA SALARY ??????
	*sector = get_integer("Enter employee sector: ", "Error. Please enter employee sector again: ", 0, 1000);					// VALORES MINIMO Y MAXIMO PARA SECTOR ??????

}

*/




















































