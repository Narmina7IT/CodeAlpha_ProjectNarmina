//main.c
#include "Task4.h"

int main(){

    while(true){

        printf("\n\tBank Account Management System.\n");
        printf("Menu:\n1.Deposit\n2.Withdraw\n3.Balance Enquiry\n4.Exit\n");
        printf("Choose an option [1-4]: ");

        int choice;
        scanf("%d", &choice);

        switch(choice){
            case 1:
                deposit();
                break;

            case 2:
                withdraw();
                break;
        
            case 3:
                balance();
                break;

            case 4:
                quit();
                break;
        
            default:
                printf("Invalid input.\n");
        }
    }


    return 0;
}
