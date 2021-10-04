#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_


#define MAXEMPLOYEES 15
#define TRUE 1
#define FALSE 0
#define MAXSTRINGLENGHT 51
#define ID 1000

struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;


int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);
int findEmployeeById(Employee* list, int len, int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int length);




// ??
void employee_enterEmployee(Employee* list, int i);
int employee_searchForEmptySpace(Employee* list, int len);
void get_id(Employee* list, int len);

// mmmhhh
void enter_employee(Employee* list, int len);
void show_employee(Employee* list);
void show_allEmployees(Employee* list, int len);

// testing
void this_isHardCode(Employee* list, int len);
//void this_isHardCode(Employee list[], int len);



#endif




