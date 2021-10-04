// TP 2

// Una empresa requiere un sistema para administrar su nómina de empleados. Se sabe que
//dicha nómina bajo ninguna circunstancia superara los 1000 empleados.

/*
El sistema deberá tener el siguiente menú de opciones:
1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
de Id. El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Salario o Sector.
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:
1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.

NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de algún empleado.
*/
#include <stdio.h>
#include <stdlib.h>

#include "ArrayEmployees.h"
#include "Inputs.h"
#include "Validaciones.h"



int main(void) {
	setbuf(stdout, NULL);
	printf("WELCOME!\n\n");
	int option;
	int contadorAltas = 0;
	int resultado;

	Employee arrayEmployees[MAXEMPLOYEES];

	initEmployees(arrayEmployees, MAXEMPLOYEES);
	for (int i = 0; i < MAXEMPLOYEES; ++i) {
		printf("%d - Value: %d\n", i, arrayEmployees[i].isEmpty);
	}
	printf("IS EMPTY = TRUE (1)\n\n");


	/*
	this_isHardCode(arrayEmployees, MAXEMPLOYEES);
	for (int i = 0; i < MAXEMPLOYEES; ++i) {
		printf("%d - Value: %d\n", i, arrayEmployees[i].isEmpty);
	}
	printf("IS EMPTY = FALSE (0)\n\n\n");
	*/


	//get_id(arrayEmployees, MAXEMPLOYEES);

	/*
	for (int i = 0; i<MAXEMPLOYEES; i++) {
		get_id(arrayEmployees, MAXEMPLOYEES);
		printf("%d - ID N° %d\n", i, arrayEmployees[i].id);
	}
	*/

	/*
	printf("Show Employee:\n");
	show_employee(arrayEmployees);

	printf("Show all Employees:\n");
	show_allEmployees(arrayEmployees, MAXEMPLOYEES);






	for (int i = 0; i < MAXEMPLOYEES; ++i) {
		printf("%d - Value: %d\n", i, arrayEmployees[i].id);
	}
	*/


	do {
		option = get_integer("Ingrese la opcion que desee:\n"
							 "-----------------------------------------------------------------------------------------------\n"
							 "1. ALTA\n"
							 "2. MODIFICAR\n"
							 "3. BAJA\n"
							 "4. INFORMAR\n"
							 "5. EXIT\n",
				             "\nError: entrada no válida. Reingrese opcion del menu:\n"
				             "-----------------------------------------------------------------------------------------------\n"
				             "1. ALTA\n"
				             "2. MODIFICAR\n"
				             "3. BAJA\n"
				             "4. INFORMAR\n"
				             "5. EXIT\n", 1, 5);

		switch (option) {
			case 1: 		// yo lo que hice fue hacer una funcion q pide todos los datos y luego llame a esa funcion y le pasas los datos que te pide.
				enter_employee(arrayEmployees, MAXEMPLOYEES);

				printf("\n\nID: %d\n"
						"Name: %s\n"
						"Last name: %s\n"
						"Salary: %f\n"
						"Sector: %d\n\n", (*arrayEmployees).id, (*arrayEmployees).name, (*arrayEmployees).lastName, (*arrayEmployees).salary, (*arrayEmployees).sector);


				resultado = addEmployee((*arrayEmployees).id, (*arrayEmployees).name, (*arrayEmployees).lastName, (*arrayEmployees).salary, (*arrayEmployees).sector);



				//aaB = addEmployee(arrayEmployees, MAXEMPLOYEES, arrayEmployees.id, arrayEmployees.name, arrayEmployees. lastName, arrayEmployees.salary, arrayEmployees.sector);
				//show_employee(arrayEmployees);
				//addEmployee(arrayEmployees, MAXEMPLOYEES, arrayEmployees.id, arrayEmployees.name, arrayEmployees.lastName, arrayEmployees.salary, arrayEmployees.sector);
				/*
				int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector) {
					int returno;




					return returno;
				}
				employee_getInformation(&arrayEmployees, arrayEmployees.name, arrayEmployees.lastName, arrayEmployees.salary, arrayEmployees.sector);
				printf("Name: %s\n"
					   "Apellido: %s\n"
					   "Salary: %f\n"
					   "Sector: %d\n", arrayEmployees.name, arrayEmployees.lastName, arrayEmployees.salary, arrayEmployees.sector);
					   */

				//addEmployee(arrayEmployees, MAXEMPLOYEES, arrayEmployees.id, arrayEmployees.name, arrayEmployees.lastName, arrayEmployees.salary, arrayEmployees.sector);






				//int addEmployee(sEmployee* list, int len, int id, char name[], char lastName[], float salary, int sector);


/*
				int addEmployee(sEmployee* list, int len, int id, char name[], char lastName[], float salary, int sector) {				 // PARA QUE TANTOS PARAMETROS ??????????
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


				contadorAltas++;
				system("pause");
				break;

			case 2:
				// MODIFICAR
				break;

			case 3:
				// BAJA
				break;

			case 4:
				// INFORMAR
				break;

			case 5:
				printf("\n\nThank you for being there! Bye");
				break;
		}
	} while (option != 5);


	return EXIT_SUCCESS;
}




/*
 * 		switch(opcion) {
			case 1:
				if (!producto_agregarProducto(arrayProductos, TAM)) {
					cantidadProductos++;
				}
				system("pause");
				break;

			case 2:
				producto_mostrarTodos(arrayProductos, TAM);
				if (!producto_borrarUno(arrayProductos, TAM)) {
					cantidadProductos--;
				}
				system("pause");
				break;

			case 3:

				break;

			case 4:
				if (cantidadProductos > 0) {
					producto_mostrarTodos(arrayProductos, TAM);
				} else {
					printf("\nNo hay productos cargados en el sistema.\n\n");
				}
				system("pause");
				break;

			case 5:
				if (cantidadProductos > 0) {
					producto_ordenarProductosPorPrecioAsc(arrayProductos, TAM);
				} else {
					printf("\nNo hay productos cargados en el sistema.\n\n");
				}
				system("pause");
				break;

			case 6:
				if (cantidadProductos > 0) {
					producto_ordenarProductosPorDescripcionAsc(arrayProductos, TAM);
				} else {
					printf("\nNo hay productos cargados en el sistema.\n\n");
				}
				system("pause");
				break;

			case 7:
				printf("Saliendo...\nPrograma terminado.\n");
				break;
		}
	} while (opcion != 7);
 */















