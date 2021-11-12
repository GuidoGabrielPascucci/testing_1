#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Inputs.h"


int main() {
	setbuf(stdout, NULL);

    int option = 0;
    int retorno;
    //int contadorID = 0;
    int flag = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{

    	getIntInMinMaxRange(&option, "\n-------------------------------------------------------------------------------------------------------------------\n\n"
									 "MENU\n\n"
									 "-------------------------------------------------------------------------------------------------------------------\n"
									 "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
									 "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
									 "3. Alta de empleado\n"
									 "4. Modificar datos de empleado\n"
									 "5. Baja de empleado\n"
									 "6. Listar empleados\n"
									 "7. Ordenar empleados\n"
									 "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
									 "9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n\n"
									 "10. Salir\n"
									 "-------------------------------------------------------------------------------------------------------------------\n"
									 "Ingrese una opcion: ",

									 "\n\n\nERROR! <<La opcion ingresada no es correcta>>\n"
									 "-------------------------------------------------------------------------------------------------------------------\n"
									 "MENU\n\n"
									 "-------------------------------------------------------------------------------------------------------------------\n"
									 "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
									 "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
									 "3. Alta de empleado\n"
									 "4. Modificar datos de empleado\n"
									 "5. Baja de empleado\n"
									 "6. Listar empleados\n"
									 "7. Ordenar empleados\n"
									 "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
									 "9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n\n"
									 "10. Salir\n"
									 "-------------------------------------------------------------------------------------------------------------------\n"
									 "Reingrese una opcion: ", 1, 10);


        switch(option)
        {
            case 1:
            	retorno = controller_loadFromText("dataText.csv", listaEmpleados);
            	if(retorno) {
            		printf("\n\n\n*******************************************************************************************************************\n\n"
            				"Se ha cargado el archivo de texto exitosamente!\n\n"
            				"*******************************************************************************************************************\n\n");
            		flag = 1;
            	}
            	else {
            		printf("\n\n\nError al abrir el archivo\n\n");
            	}

            	system("pause");
                break;

            case 2:
            	retorno = controller_loadFromBinary("dataBinary.csv", listaEmpleados);
            	if(retorno) {
            		printf("\n\n\n*******************************************************************************************************************\n\n"
            				"Se ha cargado el archivo binario exitosamente!\n\n"
            				"*******************************************************************************************************************\n\n");
            		flag = 1;
            	}
            	else {
            		printf("\n\n\nError al abrir el archivo\n\n");
            	}

            	system("pause");
            	break;

            case 3:
            	/// 3. Alta de empleado
            	if(flag) {
                	retorno = controller_addEmployee(listaEmpleados);
                	if(retorno) {
                		printf("\n\n\n*******************************************************************************************************************\n\n"
                				"Se ha cargado un empleado exitosamente!\n\n"
                				"*******************************************************************************************************************\n\n");
                	}
                	else {
                		printf("\n\n\nERROR! <<No se ha podido cargar el empleado en el sistema>>\n");
                	}

            	}
            	else {
            		printf("\n\n\nERROR! <<No hay empleados cargados en el sistema>>\n");
            	}

            	system("pause");

            	break;

            case 4:
            	/// 4. Modificar datos de empleado
            	if(flag) {
                	//controller_editEmployee();
                	//int controller_editEmployee(LinkedList* pArrayListEmployee);
            	}
            	else {
            		printf("\n\n\nERROR! <<No hay empleados cargados en el sistema>>\n");
            	}

            	system("pause");
            	break;

            case 5:
            	/// 5. Baja de empleado
            	if(flag) {
            		do {
            			retorno = controller_removeEmployee(listaEmpleados);

            			switch(retorno) {
							case -1: /// LINKED LIST NULL
								printf("\n\n\nERROR! <<Lista nula>>\n");
								system("pause");
								break;

							case 0: /// BORRO EMPLEADO
		                		printf("\n\n\n*******************************************************************************************************************\n\n"
		                				"Se ha removido un empleado exitosamente!\n\n"
		                				"*******************************************************************************************************************\n\n");
		                		system("pause");

		                		getIntInMinMaxRange(&retorno, "\n\n¿Desea seguir eliminando empleados de la lista?\n"
		                									  "-------------------------------------------------------------------------------------------------------------------\n"
		                									  "1. Eliminar otro empleado\n"
		                									  "2. Volver al Menu Principal\n\n\n",

															  "\n\nERROR! <<Numero ingresado invalido>>\n"
															  "Por favor reingrese una opcion...\n\n"
															  "¿Desea seguir eliminando empleados de la lista?\n"
															  "-------------------------------------------------------------------------------------------------------------------\n"
															  "1. Eliminar otro empleado\n"
															  "2. Volver al Menu Principal\n\n\n", 1, 2);

		                		switch (retorno) {

									case 2:
										retorno = -1;
										break;
		                		}

		                		printf("\n\n\n");
								break;

							case 1: /// CANCELO EN LA VERIFICACION
								printf("\n\n\nEl empleado sigue cargado en el sistema\n");
								system("pause");
								break;
            			}


            		} while(retorno != -1 && retorno != 3);

            	}
            	else {
            		printf("\n\n\nERROR! <<No hay empleados cargados en el sistema>>\n");
            		system("pause");
            	}

            	break;

            case 6:
            	if(flag) {
                	controller_ListEmployee(listaEmpleados);
                	printf("\n\n");
            	}
            	else {
            		printf("\n\n\nERROR! <<No hay empleados cargados en el sistema>>\n");
            	}

            	break;

            case 7:
            	/// 7. Ordenar empleados
            	if(flag) {
                	//controller_sortEmployee();
                	//int controller_sortEmployee(LinkedList* pArrayListEmployee);
            	}
            	else {
            		printf("\n\n\nERROR! <<No hay empleados cargados en el sistema>>\n");
            	}

            	system("pause");
            	break;

            case 8:
            	if(flag) {
            		retorno = controller_saveAsText("dataText.csv", listaEmpleados);
            		if(retorno) {
            			printf("\n\n\n*******************************************************************************************************************\n\n"
            					"Se ha guardado el archivo de texto exitosamente!\n\n"
            					"*******************************************************************************************************************\n\n");
            		}
            		else {
            			printf("\n\n\nError al abrir el archivo\n\n");
            		}
            	}
            	else {
            		printf("\n\n\nERROR! <<No hay empleados cargados en el sistema>>\n");
            	}

            	system("pause");
            	break;

            case 9:
            	if(flag) {
            		retorno = controller_saveAsBinary("dataBinary.csv", listaEmpleados);
            		if(retorno) {
                		printf("\n\n\n*******************************************************************************************************************\n\n"
                				"Se ha guardado el archivo binario exitosamente!\n\n"
                				"*******************************************************************************************************************\n\n");
            		}
            		else {
            			printf("\n\n\nError al abrir el archivo\n\n");
            		}
            	}
            	else {
            		printf("\n\n\nERROR! <<No hay empleados cargados en el sistema>>\n");
            	}

            	system("pause");
            	break;

            case 10:
            	/// 10. Salir
            	printf("\n\nSee you later!\n"
            		   "Exit program...");
            	break;
        }
    }while(option != 10);
    return 0;
}

