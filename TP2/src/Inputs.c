
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include "Validaciones.h"





int get_integer(char* message, char* errorMessage, int min, int max) {
	int enterIntNumber;

	printf("%s", message);
	fflush(stdin);
	scanf("%d", &enterIntNumber);

	while (enterIntNumber < min || enterIntNumber > max) {
		printf("%s", errorMessage);
		fflush(stdin);
		scanf("%d", &enterIntNumber);
	}

	return enterIntNumber;
}




void get_string(char* string, char* message, char* errorMessage, int max) {
	char notValidateString[200];
	int lenght;

	printf("%s", message);
	fflush(stdin);
	scanf("%[^\n]", notValidateString);
	lenght = strlen(notValidateString);

	while(lenght > max)
	{
		printf("%s", errorMessage);
		fflush(stdin);
		scanf("%[^\n]", notValidateString);
		lenght = strlen(notValidateString);
	}

	strcpy(string, notValidateString);
}




float get_float(char* message, char* errorMessage, int min, int max) {
	float enterFloatNumber;

	printf("%s", message);
	fflush(stdin);
	scanf("%f", &enterFloatNumber);

	while (enterFloatNumber < min || enterFloatNumber > max) {
		printf("%s", errorMessage);
		fflush(stdin);
		scanf("%f", &enterFloatNumber);
	}

	return enterFloatNumber;
}













/*
int get_integerModularized(char* message, int min, int max) {
	int addIntNumber;
	int validatedNumber;

	printf("%s", message);
	fflush(stdin);
	scanf("%d", &addIntNumber);
	validatedNumber = validate_intNumber(addIntNumber, min, max);

	return validatedNumber;
}


int pedirEntero_noModularizado(char* mensaje, char* mensajeError, int min, int max) {
	int addIntNumber;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &addIntNumber);

	while (addIntNumber < min || addIntNumber > max) {
		printf("%s", mensajeError);
		fflush(stdin);
		scanf("%d", &addIntNumber);
	}

	return addIntNumber;
}


int pedirEntero_sinValidar(char* mensaje) {
	int addIntNumber;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &addIntNumber);

	return addIntNumber;
}


int get_enteroPorParametro(int* entero, char* mensaje, char* mensajeError, int min, int max) {
	int retorno = -1;
	int numeroIngresado;

	if(entero != NULL && mensaje != NULL && mensajeError != NULL && min < max) {
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%d", &numeroIngresado);

		while (numeroIngresado < min || numeroIngresado > max) {
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%d", &numeroIngresado);
		}

		*entero = numeroIngresado;
		retorno = 0;
	}

	return retorno;
}


// FLOTANTES
float getFloat(char* mensaje, int min, int max) {
	float addFloatNumber;
	float numeroValidado;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%f", &addFloatNumber);
	numeroValidado = validar_numeroFlotante(addFloatNumber, min, max);

	return numeroValidado;
}


int get_floatPorParametro(float* flotante, char* mensaje, char* mensajeError, int min, int max) {
	int retorno = -1;
	float numeroIngresado;

	if(flotante != NULL && mensaje != NULL && mensajeError != NULL && min < max) {
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%f", &numeroIngresado);

		while (numeroIngresado < min || numeroIngresado > max) {
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%f", &numeroIngresado);
		}

		*flotante = numeroIngresado;
		retorno = 0;
	}

	return retorno;
}


// ESTA FUNCION ES EXACTAMENTE LA MISMA QUE pedirEntero_sinValidar
int seguir_ingresoDeDatosModoInt(char* mensaje) {
	int iterador;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &iterador);

	return iterador;
}



int get_character(char* caracter, char* mensaje) {
	int retorno = -1;
	if (caracter != NULL && mensaje != NULL) {
		printf("%s", mensaje);
		fflush(stdin);
		*caracter = getchar();
		retorno = 0;
	}

	return retorno;
}


*/










