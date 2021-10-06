/*
#ifndef TESTING_H_
#define TESTING_H_


#define TRUE 1
#define FALSE 0
#define MAXEMPLOYEES 15
#define MAX_STRING_LEN 51


struct {
    int id;
    char name[MAX_STRING_LEN];
    char lastName[MAX_STRING_LEN];
    float salary;
    int sector;
    int isEmpty;
} typedef Employee;


// validations
void get_and_validate_string(char* string, char* message, char* errorMessage, int max);
int get_empty_space(Employee* list, int len);

// bussines logic
int generate_id();
int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len, int id);








#endif
*/
