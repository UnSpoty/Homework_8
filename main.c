#include <stdio.h>
#include <dlfcn.h>
//#include "includes.h" Using dyn. lib

// Переписать программу из задания на статические библиотеки так чтобы
//применялась динамическая библиотека. Т. е. чтобы весь функционал
//находился в динамической библиотеке.

int main() {

    void *handle = dlopen("./libDyn_lib_Homework.so", RTLD_LAZY); // Загрузка динамической библиотеки
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

    int choice = 0;
    int num1, num2, result;

    int (*func_addition_ref)(int, int);
    int (*func_subtraction_ref)(int, int);
    int (*func_multiplication_ref)(int, int);
    int (*func_division_ref)(int, int);

    func_addition_ref = dlsym(handle, "func_addition");  // Получение указателей на функции из динамической библиотеки
    func_subtraction_ref = dlsym(handle, "func_subtraction");
    func_multiplication_ref = dlsym(handle, "func_multiplication");
    func_division_ref = dlsym(handle, "func_division");

    do {
        printf("\nChose operation:\n");
        printf("1) Add\n");
        printf("2) Subtract\n");
        printf("3) Multiply\n");
        printf("4) Division\n");
        printf("5) Exit\n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nNum X: ");
                scanf("%d", &num1);
                printf("\nNum Y: ");
                scanf("%d", &num2);
                result = func_addition_ref(num1, num2);
                printf("\nResult: %d\n", result);
                break;
            case 2:
                printf("\nNum X: ");
                scanf("%d", &num1);
                printf("\nNum Y: ");                           
                scanf("%d", &num2);       
                result = func_subtraction_ref(num1, num2); 
                printf("\nResult: %d\n", result);
                break; 
            case 3:
                printf("\nNum X: ");
                scanf("%d", &num1);
                printf("\nNum Y: ");
                scanf("%d", &num2);       
                result = func_multiplication_ref(num1, num2);
                printf("\nResult: %d\n", result);
                break;
            case 4:        
                printf("\nNum X: ");
                scanf("%d", &num1);
                printf("\nNum Y: ");                         
                scanf("%d", &num2);       
                result = func_division_ref(num1, num2);
                printf("\nResult: %d\n", result);
                break; 
            case 5:
                printf("Exit.\n");
                break;
            default:
                printf("Wrong operation.\n");
        }
    } while (choice != 5);
    
    dlclose(handle); 

    return 0;
}