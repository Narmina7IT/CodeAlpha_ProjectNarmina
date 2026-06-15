//Task4.c
#include "Task4.h"

#define DATA_FILE "file.csv"

void deposit(){
    struct User u;
    struct User input;
    bool isFound = false;

    printf("\nInput the card number: ");
    scanf("%d", &input.card);
    printf("How much money you want to put on your card?: ");
    float money;
    scanf("%f", &money);
    
    FILE *file = fopen(DATA_FILE, "a+");
    FILE *temp = fopen("temp.csv", "w");

    if(file == NULL || temp == NULL){
        printf("There is an error!\n");
        if(file) fclose(file);
        if(temp) fclose(temp);
        return;
    }    

    while(fscanf(file, " %9[^,],%9[^,],%d,%f\n", u.Name, u.Surname, &u.card, &u.balance) == 4){
        if(u.card == input.card){
            u.balance += money;
            printf("\nYou sucsesfully deposited the money!\n");
            isFound = true;
        }
        fprintf(temp, "%s,%s,%d,%.2f\n", u.Name,u.Surname, u.card, u.balance);
    }    

    if(!isFound){
        printf("\nYou are new for this system!\nPLease enter needed information.\nName: ");
        scanf("%9s", input.Name);
        printf("Surname: ");
        scanf("%9s", input.Surname);
        input.balance = money;
        fprintf(temp, "%s,%s,%d,%.2f\n", input.Name, input.Surname, input.card, input.balance);
        printf("\nYou sucsesfully are added to the bank system!\n");
    }

    fclose(file);
    fclose(temp);

    remove(DATA_FILE);
    rename("temp.csv", DATA_FILE);
}

void withdraw(){

    struct User u;
    int card;
    float money;
    bool isFound = false;

    printf("\nInput your card number: ");
    scanf("%d", &card);
    printf("Enter the number of money you want to withdraw: ");
    scanf("%f", &money);

    if (money <0){//negative number control
        printf("\nYou cant withdraw this amount of money!\n");
        return;
    }

    FILE *file = fopen(DATA_FILE, "r");
    FILE *temp = fopen("temp.csv", "w");
    if(file == NULL || temp == NULL){
        if(file) fclose(file);
        if(temp) fclose(temp);
        return;
    }

    while(fscanf(file, " %9[^,],%9[^,],%d,%f\n", u.Name, u.Surname, &u.card, &u.balance) == 4){
        if(card == u.card){
            isFound = true;
            if(money > u.balance){
                printf("\nYou cant withdraw the money! Your balance is: %.2f\n", u.balance);
            } else{
                u.balance -= money;
                printf("\nYou sucsesfully completed the withdrawal process!\n");
            }
        }
        fprintf(temp, "%s,%s,%d,%.2f\n", u.Name, u.Surname, u.card, u.balance);
    }

    fclose(file);
    fclose(temp);

    if(!isFound){
        printf("There is no user with such card!\n");
        remove("temp.csv");
        return;
    }

    remove(DATA_FILE);
    rename("temp.csv", DATA_FILE);

}

void balance(){

    struct User u;
    int card;
    bool isFound = false;

    printf("\nPlease input the card to see your information: ");
    scanf("%d", &card);

    FILE *file = fopen(DATA_FILE, "r");
    if(file == NULL){
        printf("Error!\n");
        return;
    }

    while(fscanf(file, " %9[^,],%9[^,],%d,%f\n", u.Name, u.Surname, &u.card, &u.balance) == 4){
        if(card == u.card){
            printf("\nName: %-12s\nSurname: %-12s\nCard: %-9d\nBalance: %.2f\n", u.Name,u.Surname, u.card, u.balance);
            isFound = true;
            break;
        }
    }

    if(!isFound){
        printf("\nThere is no user with such card.\n");
    }

    fclose(file);
}

void quit(){

    printf("\nYou are exiting!\nGood luck!\n");
    exit(0);

}
