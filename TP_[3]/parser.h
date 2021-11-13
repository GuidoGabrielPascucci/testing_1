
#ifndef PARSER_H_
#define PARSER_H_


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);


int cargarDatosDeEmpleado(LinkedList* pArrayListEmployee, Employee *pEmployee);							/// CAMBIAR DE BIBLIOTECA
int editarEmpleado(Employee* pEmployee);																/// CAMBIAR DE BIBLIOTECA
int removerEmpleado(Employee* pEmployee, LinkedList* pArrayListEmployee, int index);					/// CAMBIAR DE BIBLIOTECA
int confirmarRemoverEmpleado(void);																		/// CAMBIAR DE BIBLIOTECA




int sortByID(Employee* pEmployeeA, Employee* pEmployeeB);												/// CAMBIAR DE BIBLIOTECA
int sortByName(Employee* pEmployeeA, Employee* pEmployeeB);												/// CAMBIAR DE BIBLIOTECA
int sortByHours(Employee* pEmployeeA, Employee* pEmployeeB);											/// CAMBIAR DE BIBLIOTECA
int sortBySalary(Employee* pEmployeeA, Employee* pEmployeeB);											/// CAMBIAR DE BIBLIOTECA


#endif
