
#ifndef INPUTS_H_
#define INPUTS_H_



int getIntInMinMaxRange(char* message, char* errorMessage, int min, int max);
int getNumeroMayorQueMinimo(char* message, char* errorMessage, int min);
float getFloatInMinMaxRange(char* message, char* errorMessage, int min, int max);
void getString(char* string, char* message, char* errorMessage, int max);




/*
int pedirEntero(char* mensaje, int min, int max);
int pedirEntero_noModularizado(char* mensaje, char* mensajeError, int min, int max);
int pedirEntero_sinValidar(char* mensaje);
int get_enteroPorParametro(int* entero, char* mensaje, char* mensajeError, int min, int max);

float getFloat(char* mensaje, int min, int max);
int get_floatPorParametro(float* flotante, char* mensaje, char* mensajeError, int min, int max);

int seguir_ingresoDeDatosModoInt(char* mensaje);

int get_character(char* caracter, char* mensaje);
*/



#endif
