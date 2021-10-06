/*
#include <stdio.h>
#include <string.h>
#include "testing.h"



int main()
{
    Employee list[MAXEMPLOYEES];
    Employee emp;
    int index;

    initEmployees(list, MAXEMPLOYEES);

    // armar un menu copado, y como parametro del switch, es lo que elige de los printf
  	    // printf("Entering a new employee...\n"); -> 1
  	    // printf("\n");
	    // printf("Remover a employee...\n"); -> 2
  	    // printf("\n");
    switch (2) {
      case 1:
        // pido los campos del Empleado
        get_and_validate_string(emp.name, "Dame un nombre: ", "Nombre invalido, ingrese otro: ", MAX_STRING_LEN);
        get_and_validate_string(emp.lastName, "Dame un Apellido: ", "Apellido invalido, ingreso otro: ", MAX_STRING_LEN);

        // validar integer como con lo de string
        emp.salary = 1000000;
        emp.sector = 0;
        emp.isEmpty = FALSE;

        addEmployee(list, MAXEMPLOYEES, emp.id, emp.name, emp.lastName, emp.salary, emp.sector);
      break;

      case 2:
        findEmployeeById(list, MAXEMPLOYEES, 1);
      break;
      case 3:
        // encontrar mediante for el ID que llega por paramtro y poner esa posicion de la lista en NULL o pasar isEmpty a TRUE
        removeEmployee(list, MAXEMPLOYEES, 1);
      break;
    }
    return 0;
}

int initEmployees(Employee* list, int len) {
	int exit = -1;

	if (list != NULL && len > 0) { // LEN < -1 ???
		for (int i = 0; i < len; ++i) {
			list[i].isEmpty = TRUE;
		}
		exit = 0;
	} else {
		printf("Invalid length or NULL pointer...\n\n");
	}

	return exit;
}

int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector) {
    Employee emp;
    int index;

    // valido si tengo espacio y retorno el index
    index = get_empty_space(list, len);

    // sacar a una función
	if(index != -1) {
       // asigno
       	// armar funcion para generar id
        emp.id = generate_id();
        strcpy(emp.name, name);
        strcpy(emp.lastName, lastName);
        emp.salary = salary;
        emp.sector = sector;
        list[index] = emp;
        printf("El empleado con nombre: %s, fue agregado exitosamente", list[index].name);
        return emp.id;
	} else {
		printf("Error. No empty space to enter an employee...\n");
        return -1;
	}
}

void get_and_validate_string(char* string, char* message, char* errorMessage, int max) {
	char notValidateString[200];
	int lenght;

	printf("%s", message);
	fflush(stdin);
	// ver que pasa con la mascara que no funciona
	scanf("%s", notValidateString);
	lenght = strlen(notValidateString);

	while (lenght > max)
	{
		printf("%s", errorMessage);
		fflush(stdin);
		scanf("%s", notValidateString);
		lenght = strlen(notValidateString);

	}

	strcpy(string, notValidateString);
}

int get_empty_space(Employee* list, int len) {
	int index = -1;
	for (int i = 0; i < len; ++i) {
		if (list[i].isEmpty == TRUE) {
			index = i;
			break;
		}
	}
	return index;
}

int generate_id() {
    return 1;
}

int findEmployeeById(Employee* list, int len,int id) {

    // sacar el hardcodeo para que esto se haga por el menu copado.
    Employee emp = { 1, "pablo", "sanchez", 1000000, 0 };
    list[0] = emp;

    for(int i = 0;i < len; i++) {
        if(list[i].id == id) {
            printf("la posición es: %d", i);
            return i;
        }
    }

    return -1;
}

int removeEmployee(Employee* list, int len,int id) {

    // sacar el hardcodeo para que esto se haga por el menu copado.
    Employee emp = { 1, "pablo", "sanchez", 1000000, 0 };
    list[0] = emp;

    for(int i = 0;i < len; i++) {
        if(list[i].id == id) {
            list[i].isEmpty = TRUE;
            // list[i] = NULL
        }
    }

    return -1;
}
*/
