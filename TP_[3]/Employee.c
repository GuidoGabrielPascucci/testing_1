
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"



Employee* employee_new() {

	Employee *pEmployee = NULL;
	pEmployee = (Employee*) malloc(sizeof(Employee));

	return pEmployee;
}



Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr) {

	Employee *pEmployee = NULL;
	pEmployee = employee_new();

	if(pEmployee != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL) {
		employee_setId(pEmployee, atoi(idStr));
		employee_setNombre(pEmployee, nombreStr);
		employee_setHorasTrabajadas(pEmployee, atoi(horasTrabajadasStr));
		employee_setSueldo(pEmployee, atoi(sueldoStr));
	}

	return pEmployee;
}



void employee_delete(Employee* this) {

	if(this != NULL) {
		free(this);
		this = NULL;
	}

}



int employee_setId(Employee* this, int id) {

	int retorno = 0;

	if(this != NULL) {
		this->id = id;
		retorno = 1;
	}

	return retorno;
}



int employee_getId(Employee* this, int* id) {

	int retorno = 0;
	if(this != NULL) {
		*id = this->id;
	}

	return retorno;
}



int employee_setNombre(Employee* this, char* nombre) {

	int retorno = 0;

	if(this != NULL) {
		strcpy(this->nombre, nombre);
		retorno = 1;
	}

	return retorno;
}



int employee_getNombre(Employee* this, char* nombre) {

	int retorno = 0;
	if(this != NULL) {
		strcpy(nombre, this->nombre);
	}

	return retorno;
}



int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas) {

	int retorno = 0;

	if(this != NULL) {
		this->horasTrabajadas = horasTrabajadas;
		retorno = 1;
	}

	return retorno;
}



int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas) {

	int retorno = 0;
	if(this != NULL) {
		*horasTrabajadas = this->horasTrabajadas;
	}

	return retorno;
}



int employee_setSueldo(Employee* this, int sueldo) {

	int retorno = 0;

	if(this != NULL) {
		this->sueldo = sueldo;
		retorno = 1;
	}

	return retorno;
}



int employee_getSueldo(Employee* this, int* sueldo) {

	int retorno = 0;
	if(this != NULL) {
		*sueldo = this->sueldo;
	}

	return retorno;
}




