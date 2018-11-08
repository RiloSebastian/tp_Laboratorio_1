#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} Employee;


int employee_init(Employee listEmployees[], int len);

int set_id(Employee listEmployees[], int len);

int employee_add(Employee listEmployees[] , int len);

int employee_modify(Employee listEmployees[], int len);

int employee_findById(Employee listEmployees[] , int len, int id);

int employee_remove(Employee listEmployees[] , int len);

int employee_sort(Employee listEmployees[] , int len, int order);

int employee_print(Employee listEmployees[] , int len);

int employee_printSorted(Employee listEmployees[] , int len);

int employee_printOne(Employee listEmployees[] ,int len, int id);

int search_closestEmptySpace(Employee listEmployees[] ,int len);

int employee_averageSalary(Employee listEmployees[], int len);

#endif
