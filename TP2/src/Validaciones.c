
#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"




int validate_intNumber(int intToValidate, int min, int max) {
	while (intToValidate < min || intToValidate > max) {
		printf("Validation error. Please enter a new number: ");
		fflush(stdin);
		scanf("%d", &intToValidate);
	}

	return intToValidate;
}




/*
float validar_numeroFlotante(float numeroAValidar, int min, int max) {
	while (numeroAValidar < min || numeroAValidar > max) {
		printf("Error en el ingreso. Por favor ingrese nuevamente un número: ");
		fflush(stdin);
		scanf("%f", &numeroAValidar);
	}

	return numeroAValidar;
}





void validar_intDistintoDeCero(int* array, int tam, char* mensajeError) {
	while (array == 0) {
		printf(mensajeError);
		fflush(stdin);
		scanf("%d", &array);
	}
}

*/


























