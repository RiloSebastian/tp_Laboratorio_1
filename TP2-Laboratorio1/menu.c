#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "Validaciones.h"
#define eLEN 1000

int menu(void)
{
    Employee list[eLEN];
    int option;
    int flag=0;

    if(employee_init(list,eLEN))
    {

        do
        {
            printf("\n 1. ADD EMPLOYEE\n");
            printf(" 2. MODIFY EMPLOYEE\n");
            printf(" 3. REMOVE EMPLOYEE\n");
            printf(" 4. SHOW\n");
            printf(" 5. EXIT\n");
            printf("\n Choose an option: ");
            scanf("%d",&option);
            switch(option)
            {
            case 1:
                if(employee_add(list,eLEN))
                {
                    printf("\n Employee succesfully added.\n");
                    flag=1;
                }
                else
                {
                    printf(" Error. something happened.\n");
                }
                break;
            case 2:
                if(flag==1)
                {
                    employee_print(list,eLEN);
                    if(employee_modify(list,eLEN))
                    {
                        printf("\n Employee succesfully modified.\n");
                    }
                    else
                    {
                        printf(" The employee you tried to modify doesn't exist.\n");
                    }
                }
                else
                {
                    printf(" You can't modify an employee if you haven't added any yet.\n");
                }
                break;
            case 3:
                if(flag==1)
                {
                    employee_print(list,eLEN);
                    if(employee_remove(list,eLEN))
                    {
                        printf("\n Employee succesfully removed.\n");
                    }
                    else
                    {
                        printf(" The employee you tried to remove doesn't exist.\n");
                    }
                }
                else
                {
                    printf(" You can't remove an employee if you haven't added any yet.\n");
                }
                break;
            case 4:
                if(flag==1)
                {
                    if(employee_printSorted(list,eLEN))
                    {
                        printf("\n Employee's list printed.\n");
                    }
                    else
                    {
                        printf("\n An error has ocurred.\n");
                    }
                }
                else
                {
                    printf(" You can't inform about the employees if you haven't added any yet.\n");
                }
                break;
            case 5:
                //salir
                break;
            default :
                printf("\n This option doesn't exist.\n");
                break;
            }
        }
        while(option!=5);
    }
    return 0;
}

