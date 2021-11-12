
#ifndef PARSER_H_
#define PARSER_H_


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);


int cargarDatosDeEmpleado(LinkedList* pArrayListEmployee, Employee *pEmployee);		/// CAMBIAR DE BIBLIOTECA
int confirmarRemoverEmpleado(void);													/// CAMBIAR DE BIBLIOTECA


#endif
