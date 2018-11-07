#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "Validaciones.h"

int employee_init(Employee listEmployees[], int len)
{
    int i;
    int flag=1;
    if(listEmployees != NULL)
    {
        for(i=0; i<len; i++)
        {
            strncpy(listEmployees[i].name,"---",sizeof(listEmployees[i].name));
            strncpy(listEmployees[i].lastName,"---",sizeof(listEmployees[i].lastName));
            listEmployees[i].sector=0;
            listEmployees[i].salary=0;
            listEmployees[i].isEmpty=1;
        }

        int id[5]= {1,2,3,4,5};
        char name[5][51]= {"Juan","Luis","Maria","Jose","emiliano"};
        char lastName[5][51]= {"juanes","alvarez","balbin","iglesias","johnson"};
        int sector[5]= {1,1,2,3,3};
        float salary[5]= {13.50,150.25,400.60,80.75,1500.30};
        int isEmpty[5]= {0,0,0,0,0};

        for(i=0; i<5; i++)
        {
            strncpy(listEmployees[i].name,name[i],sizeof(listEmployees[i].name));
            strncpy(listEmployees[i].lastName,lastName[i],sizeof(listEmployees[i].lastName));
            listEmployees[i].sector=sector[i];
            listEmployees[i].salary=salary[i];
            listEmployees[i].id=id[i];
            listEmployees[i].isEmpty=isEmpty[i];
        }

    }
    return flag;
}

int employee_printSorted(Employee listEmployees[], int len)
{
     int flag=0;
    int order=-1;
    int i;

    if(listEmployees != NULL && len >0)
    {
            printf("descendant(0) or ascendant(1) order?: ");
            order=set_marginInt(order,0,1);
            employee_sort(listEmployees,len,order);
            printf("  sector       last name                name                 id        salary\n");
            printf("---------------------------------------------------------------------------------\n");
            for(i=0; i<len; i++)
            {
                employee_printOne(listEmployees,len,i);
                flag=1;
            }
            employee_averageSalary(listEmployees,len);
    }
    return flag;
}



int employee_print(Employee listEmployees[], int len)
{
    int flag=0;
    int i;

    if(listEmployees != NULL && len >0)
    {
            printf("\n  Sector       Last name                Name                 Id        Salary\n");
            printf("---------------------------------------------------------------------------------\n");
            for(i=0; i<len; i++)
            {
                employee_printOne(listEmployees,len,i);
                flag=1;
            }

    }
    return flag;
}

int employee_printOne(Employee listEmployees[],int len,int id)
{
    int flag=0;
    if(listEmployees != NULL && len>0 && id < len && id >= 0 && listEmployees[id].isEmpty==0)
    {
        printf(" %5d       %10s            %10s            %5d         $%5.2f\n",listEmployees[id].sector,listEmployees[id].lastName,listEmployees[id].name,listEmployees[id].id,listEmployees[id].salary);
        flag=1;
    }

    return flag;
}

int search_closestEmptySpace(Employee listEmployees[], int len)
{
    int index=0;
    int i;

    if(listEmployees != NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if((listEmployees[i].isEmpty)==1)
            {
                index=i;
                break;
            }
        }
    }
    return index;
}


int set_id(Employee listEmployees[], int len)
{
    static int id=0;
    static int flag=0;
    int i;
    if(listEmployees != NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
           if(listEmployees[i].isEmpty==0 && listEmployees[i].id > id && flag==0)
           {
               id= listEmployees[i].id;
           }
        }
        id=id+1;
        flag=1;
    }

    return id;
}

int employee_add(Employee listEmployees[], int len)
{
    int flag=0;
    int index;
    int id;
    char name[50];
    char lastName[50];
    float salary=0;
    int sector=0;
    int isEmpty=0;

    if(listEmployees != NULL && len >0)
    {
        index=search_closestEmptySpace(listEmployees,len);
        printf(" Set the name: ");
        set_name(name,sizeof(name));
        printf(" Set the last name: ");
        set_name(lastName,sizeof(lastName));
        printf(" Set sector(1/10): ");
        sector=set_marginInt(sector,1,10);
        printf(" Set salary: ");
        salary= set_float(salary);
        id=set_id(listEmployees,len);
        isEmpty=0;

        strncpy(listEmployees[index].name,name,sizeof(listEmployees[index].name));
        strncpy(listEmployees[index].lastName,lastName,sizeof(listEmployees[index].lastName));
        listEmployees[index].sector=sector;
        listEmployees[index].salary=salary;
        listEmployees[index].id=id;
        listEmployees[index].isEmpty=isEmpty;
        printf("\n  Sector       Last name                Name                 Id        Salary\n");
        printf("---------------------------------------------------------------------------------\n");
        employee_printOne(listEmployees,len,index);
        flag=1;
    }

    return flag;
}

int employee_remove(Employee listEmployees[], int len)
{
    int flag=0;
    int id=0;
    int index=0;
    int isEmpty=1;
    printf(" Choose an employee by id to remove: ");
    id=set_marginInt(id,1,len);
    index=employee_findById(listEmployees,len,id);
    if(index> -1)
    {
        listEmployees[index].isEmpty=isEmpty;
        flag=1;
    }

    return flag;
}



int employee_findById(Employee listEmployees[], int len, int id)
{
    int i;
    int index=-1;
    if(listEmployees!= NULL && len>0 && id< len && id > 0)
    {
        for(i=0; i<len; i++)
        {
            if(listEmployees[i].id==id && listEmployees[i].isEmpty==0)
            {
                index=i;
                break;
            }
        }
    }
    return index;
}


int employee_modify(Employee listEmployees[], int len)
{
    int flag=0;
    int option;
    char stay;
    int index;
    int id=0;
    char name[50];
    char lastName[50];
    float salary=0;
    int sector=0;

    if(listEmployees != NULL && len >0)
    {
        printf(" Choose an employee by id to modify: ");
        id=set_marginInt(id,1,len);
        index=employee_findById(listEmployees,len,id);
        if(index> -1)
        {
            do
            {
                printf(" What do you want to change?\n name(1)  last name(2)  sector(3)  salary(4)\n option: ");
                option=set_marginInt(option,1,4);
                switch(option)
                {
                case 1:

                    printf(" Set the name: ");
                    set_name(name,sizeof(name));
                    strncpy(listEmployees[index].name,name,sizeof(listEmployees[index].name));
                    break;
                case 2:
                    printf(" Set the last name: ");
                    set_name(lastName,sizeof(lastName));
                    strncpy(listEmployees[index].lastName,lastName,sizeof(listEmployees[index].lastName));
                    break;
                case 3:
                    printf(" Set sector(1/10): ");
                    sector=set_marginInt(sector,1,10);
                    listEmployees[index].sector=sector;
                    break;
                case 4:
                    printf(" Set salary: ");
                    salary= set_float(salary);
                    listEmployees[index].salary=salary;
                    break;
                default :
                    printf(" This option doesn't exist.\n");
                    break;
                }
                printf("\n  Sector       Last name                Name                 Id        Salary\n");
                printf("---------------------------------------------------------------------------------\n");
                employee_printOne(listEmployees,len,index);
                printf("\n Do you want to make more changes?(s to stay): ");
                stay=getc(stdin);
            }
            while(stay == 's');
            flag=1;

        }
    }

    return flag;
}

int employee_sort(Employee listEmployees[], int len, int order)
{
    int flag=0;
    int i;
    int j;
    Employee aux;

    if(listEmployees != NULL && len > 0)
    {

        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(order==0)
                {
                    if(listEmployees[i].sector < listEmployees[j].sector)
                    {
                        aux=listEmployees[i];
                        listEmployees[i]=listEmployees[j];
                        listEmployees[j]= aux;
                        flag = 1;
                    }
                    else if(listEmployees[i].sector == listEmployees[j].sector && strcmp(listEmployees[i].lastName,listEmployees[j].lastName)<0)
                    {
                        aux=listEmployees[i];
                        listEmployees[i]=listEmployees[j];
                        listEmployees[j]= aux;
                        flag=1;
                    }
                }
                else if(order==1)
                 {
                    if(listEmployees[i].sector > listEmployees[j].sector)
                    {
                        aux= listEmployees[j];
                        listEmployees[j]= listEmployees[i];
                        listEmployees[i]= aux;
                        flag=1;
                    }
                    else if(listEmployees[i].sector == listEmployees[j].sector && strcmp(listEmployees[i].lastName,listEmployees[j].lastName)>0)
                    {
                        aux= listEmployees[j];
                        listEmployees[j]= listEmployees[i];
                        listEmployees[i]= aux;
                        flag=1;
                    }
                 }
            }
        }
    }
    return flag;
}


int employee_averageSalary(Employee listEmployees[], int len)
{
    int flag=0;
    int ammountOfEmployees=0;
    float totalSalary=0;
    float averageSalary=0;
    int i;
    int j;

    if(listEmployees != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(listEmployees[i].isEmpty==0)
            {
                ammountOfEmployees++;
                totalSalary= totalSalary+listEmployees[i].salary;
            }
        }
        averageSalary=totalSalary/ammountOfEmployees;
        printf("\n The total salary is of: $%.2f\n",totalSalary);
        printf(" The average salary is of: $%.2f\n",averageSalary);
        printf("\n Employees with an above average salary:");
        printf("\n  Sector       Last name                Name                 Id        Salary\n");
        printf("---------------------------------------------------------------------------------\n");
        for(j=0;j<len;j++)
        {
            if(listEmployees[j].salary > averageSalary)
            {
                employee_printOne(listEmployees,len,j);
            }
        }
    }
    return flag;
}
