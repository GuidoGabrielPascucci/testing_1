#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Menu.h"
#include "ArrayEmployees.h"
#include "Inputs.h"
#include "Funciones.h"





// MUESTRA UN EMPLEADO
void show_employee(Employee* list)
{
	printf("%-10d %-20s %-20s %-20.2f %-10d\n", (*list).id, (*list).name, (*list).lastName, (*list).salary, (*list).sector);
}














