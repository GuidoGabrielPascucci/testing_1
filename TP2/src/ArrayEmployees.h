#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_


#define MAX_EMPLOYEES 5
#define TRUE 1
#define FALSE 0
#define MAX_STRING_LENGHT 51
#define ID 1000

struct
{
 int id;
 char name[MAX_STRING_LENGHT];
 char lastName[MAX_STRING_LENGHT];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;


// ---------------------------------------------------------------------------------------------------------------
// FUNCIONES IMPRESCINDIBLES:
int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);
int findEmployeeById(Employee* list, int len, int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int length);
// ---------------------------------------------------------------------------------------------------------------


// FUNCIONES NECESARIAS
int enterEmployeeData(Employee* list, int len, int* id, int idCounter, char* name, char* lastName, float* salary, int* sector);
int getEmptySpaceInArray(Employee* list, int len);
int generateId(int idCounter);
void show_employee(Employee* list); 				// CAMBIAR NOMBRE
void show_allEmployees(Employee* list, int len);	// CAMBIAR NOMBRE



// MODIFICACIONES
void modifyName(Employee* list, int len, int indexPosition);
void modifyLastName(Employee* list, int len, int indexPosition);
void modifySalary(Employee* list, int len, int indexPosition);
void modifySector(Employee* list, int len, int indexPosition);





//void employee_enterEmployee(Employee* list, int i);
//int enterEmployeeData(Employee* list, int len, int* id, char* name, char* lastName, float* salary, int* sector);
//void enter_employee(Employee* list, int len);


// testing
//void this_isHardCode(Employee* list, int len);
//void this_isHardCode(Employee list[], int len);




#endif




