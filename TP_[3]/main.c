#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Inputs.h"


int main() {
	setbuf(stdout, NULL);

    int option = 0;
    int flag = 0;
    int fileIsOpen = 0;
    int retorno;

    //int contadorID = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{

    	getIntInMinMaxRange(&option, "\n===================================================================================================================\n\n"
									 "MENU\n\n"
									 "===================================================================================================================\n"
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
									 "===================================================================================================================\n\n"
									 "Ingrese una opcion: ",


									 "\n\n\nERROR! <<La opcion ingresada no es correcta>>\n"
									 "===================================================================================================================\n"
									 "MENU\n\n"
									 "===================================================================================================================\n"
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
									 "===================================================================================================================\n\n"
									 "Reingrese una opcion: ", 1, 10);


        switch(option)
        {
            case 1:
            	if(!fileIsOpen) {

            		if(controller_loadFromText("dataText.csv", listaEmpleados)) {

            			printf("\n\n\n*******************************************************************************************************************\n\n"
            					"Se ha cargado el archivo de texto exitosamente!\n\n"
            					"*******************************************************************************************************************\n\n");

            			flag = 1;
            			fileIsOpen = 1;
            		}
            		else {
            			printf("\n\n\nError al abrir el archivo\n\n");
            		}
            	}
            	else {
            		printf("\n\nERROR. <<Operacion no valida>>\n"
            				"Ya has cargado los datos del archivo .csv al sistema!\n\n\n");
            	}

            	system("pause");
                break;

            case 2:
            	if(!fileIsOpen) {

                	if(controller_loadFromBinary("dataBinary.csv", listaEmpleados)) {

                		printf("\n\n\n*******************************************************************************************************************\n\n"
                					 "Se ha cargado el archivo binario exitosamente!\n\n"
                					 "*******************************************************************************************************************\n\n");

                		flag = 1;
                		fileIsOpen = 1;
                	}
                	else {
                		printf("\n\n\nError al abrir el archivo\n\n");
                	}
            	}
            	else {
            		printf("\n\nERROR. <<Operacion no valida>>\n"
            				"Ya has cargado los datos del archivo .csv al sistema!\n\n\n");
            	}

            	system("pause");
            	break;

            case 3:
            	if(flag) {

                	if(controller_addEmployee(listaEmpleados)) {

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
            	if(flag) {
            		do{
            			retorno = controller_editEmployee(listaEmpleados);

            			switch(retorno) {
							case -1:
								printf("\n\n\nERROR! <<Lista nula>>\n");
								system("pause");
								break;

							case 0:
								printf("\n\n\n*******************************************************************************************************************\n\n"
											 "Se han modificado los datos del empleado exitosamente!\n\n"
											 "*******************************************************************************************************************\n\n");
								system("pause");
								break;

							case 1:
								printf("\n\n\nNo se han modificado los datos del empleado\n");
								system("pause");
								break;
            			}

            			if(!retorno || retorno == 1) {
            				getIntInMinMaxRange(&retorno, "\n\n¿Que desea realizar?\n"
														  	   "-------------------------------------------------------------------------------------------------------------------\n"
														  	   "1. Modificar datos de empleado\n"
														  	   "2. Volver al Menu Principal\n\n\n",

														  "\n\nERROR! <<Opcion invalido>>\n"
															  "Por favor reingrese una opcion...\n\n"
															  "¿Desea modificar datos de empleado?\n"
															  "-------------------------------------------------------------------------------------------------------------------\n"
															  "1. Modificar datos de empleado\n"
															  "2. Volver al Menu Principal\n\n\n", 1, 2);

            				switch (retorno) {
								case 2:
									retorno = -1;
									break;
            				}
            			}

            		} while(retorno != -1 && retorno != 3);
            	}
            	else {
            		printf("\n\n\nERROR! <<No hay empleados cargados en el sistema>>\n");
                	system("pause");
            	}

            	printf("\n");
            	break;

            case 5:
            	if(flag) {
            		do {
            			retorno = controller_removeEmployee(listaEmpleados);

            			switch(retorno) {
							case -1:
								printf("\n\n\nERROR! <<Lista nula>>\n");
								system("pause");
								break;

							case 0:
		                		printf("\n\n\n*******************************************************************************************************************\n\n"
		                					 "Se ha removido un empleado exitosamente!\n\n"
		                					 "*******************************************************************************************************************\n\n");
		                		system("pause");
								break;

							case 1:
								printf("\n\n\n* El empleado sigue cargado en el sistema\n");
								system("pause");
								break;
            			}

            			if(!retorno || retorno == 1) {
	                		getIntInMinMaxRange(&retorno, "\n\n¿Que desea realizar?\n"
	                									  	   "-------------------------------------------------------------------------------------------------------------------\n"
	                									  	   "1. Eliminar un empleado\n"
	                									  	   "2. Volver al Menu Principal\n\n\n",

														  "\n\nERROR! <<Opcion invalida>>\n"
															  "Por favor reingrese una opcion...\n\n"
															  "¿Desea eliminar un empleado de la lista?\n"
															  "-------------------------------------------------------------------------------------------------------------------\n"
															  "1. Eliminar un empleado\n"
															  "2. Volver al Menu Principal\n\n\n", 1, 2);

	                		switch (retorno) {
								case 2:
									retorno = -1;
									break;
	                		}
            			}

            		} while(retorno != -1 && retorno != 3);

            	}
            	else {
            		printf("\n\n\nERROR! <<No hay empleados cargados en el sistema>>\n");
            		system("pause");
            	}

            	printf("\n");
            	break;

            case 6:
            	if(flag) {
                	controller_ListEmployee(listaEmpleados);
                	printf("\n\n");
            	}
            	else {
            		printf("\n\n\nERROR! <<No hay empleados cargados en el sistema>>\n\n");
            	}

            	system("pause");
            	break;

            case 7:
            	if(flag) {

            		if(controller_sortEmployee(listaEmpleados)) {

                		printf("\n\n\n*******************************************************************************************************************\n\n"
            						 "Se han ordenado los datos exitosamente!\n\n"
            						 "*******************************************************************************************************************\n\n");
                	}
                	else {
                		printf("\n\nHa ocurrido un error...\n\n");
                	}
            	}
            	else {
            		printf("\n\n\nERROR! <<No hay empleados cargados en el sistema>>\n");
            	}

            	system("pause");
            	break;

            case 8:
            	if(flag) {

            		if(controller_saveAsText("dataText.csv", listaEmpleados)) {

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

            		if(controller_saveAsBinary("dataBinary.csv", listaEmpleados)) {

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
            	printf("\n\n\n"
            			"===================================================================================================================\n"
            			"Programa finalizado!\n"
            			"===================================================================================================================");
            	break;
        }

    } while(option != 10);


    return 0;
}

