//Student System
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define DATA_FILE "file.csv"

void menu();
void add();
void delete();
void update();
void search();
void display();

struct Student{
    char Name[10];
    char Surname[10];
    int ID;
    float gpa;
};

int main(){

    menu();

    return 0;
}

void menu(){
    printf("Hello, dear user!\nThis ADUSD(Add, Delete, Update, Search, Display)! And we are very pleased to serve you.\n");
    while(1){
        printf("\nMenu:\n1.Add\n2.Delete\n3.Update\n4.Search\n5.Display\n6.Exit\nChoose an option [1-6]: ");
        int choice;
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add();
                break;

            case 2:
                delete();
                break;

            case 3:
                update();
                break;

            case 4:
                search();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("You are exiting!\n");
                return; //exit(0)
            default:
                printf("Invalid input! Try existing options.\n");
        }
    }
}

void add(){
    struct Student s;

    printf("Enter the name for new student: ");
    scanf("%9s", s.Name);
    printf("Enter the surname for %s student: ", s.Name);
    scanf("%9s", s.Surname);
    printf("WHat is the ID of %s %s?: ", s.Name, s.Surname);
    scanf("%d", &s.ID);
    printf("Enter the gpa: ");
    scanf("%f", &s.gpa);

    FILE *file = fopen(DATA_FILE, "a");
    if(file == NULL){
        printf("Error!\n");
        return;
    }

    fprintf(file, "%s;%s;%d;%.2f\n", s.Name, s.Surname, s.ID, s.gpa);

    fclose(file);
    printf("You succesfully added new student to the list!\n\n");
}

void delete(){
    FILE *file = fopen(DATA_FILE, "r");
    FILE *temp = fopen("temp.csv", "w");
    if(file == NULL || temp == NULL){
        printf("Error!\n");
        if(file) fclose(file);
        if(temp) fclose(temp);
        return;
    }

    int deleteID;
    bool isDeleted = false;
    struct Student s;

    printf("Enter the ID of the student u want to delete: ");
    scanf("%d", &deleteID);

    while(fscanf(file, " %[^;];%[^;];%d;%f\n", s.Name, s.Surname, &s.ID, &s.gpa) == 4){
        if(s.ID == deleteID){
            isDeleted = true;
            continue;
        }
        fprintf(temp,"%s;%s;%d;%.2f\n", s.Name, s.Surname, s.ID, s.gpa);
    }

    fclose(temp);
    fclose(file);

    if(isDeleted){
        remove(DATA_FILE);
        rename("temp.csv", DATA_FILE);
        printf("You sucessfully deleted the student with %d ID!\n\n", deleteID);
    } else{
        remove("temp.csv");
        printf("Student with %d ID is not found.\n\n", deleteID);
    }
}

void update(){
    FILE *file = fopen(DATA_FILE, "r");
    FILE *temp = fopen("temp.csv", "w");
    if(file == NULL || temp == NULL){
        printf("Error!\n");
        if(file) fclose(file);
        if(temp) fclose(temp);
        return;
    }

    struct Student s;
    int updatedId;
    bool isUpdated = false;

    printf("Enter the ID of the student whose information u want to change: ");
    scanf("%d", &updatedId);

    while(fscanf(file, " %[^;];%[^;];%d;%f\n", s.Name, s.Surname, &s.ID, &s.gpa) == 4){
        if(s.ID == updatedId){
            isUpdated = true;
            printf("Student:\nName: %s\nSurname: %s\nID: %d\nGPA: %.2f\n", s.Name, s.Surname, s.ID, s.gpa);
            bool updating = true;

            while(updating){
                printf("What do you want to change?\n1.Name\n2.Surname\n3.ID\n4.GPA\n5.Exit\nYour answer[1-5]: ");
                int choice;
                scanf("%d", &choice);

                switch(choice){
                case 1:
                    printf("New name: ");
                    scanf("%9s", s.Name);
                    break;
                case 2:
                    printf("New surame: ");
                    scanf("%9s", s.Surname);
                    break;
                case 3:
                    printf("New ID: ");
                    scanf("%d", &s.ID);
                    break;
                case 4:
                    printf("New GPA: ");
                    scanf("%f", &s.gpa);
                    break;
                case 5:
                    printf("U are exiting.\n");
                    updating = false;
                    break;
                default:
                    printf("Invalid input!\n");

                }

            }
        }
        fprintf(temp, "%s;%s;%d;%.2f\n", s.Name, s.Surname, s.ID, s.gpa);
    }

    fclose(file);
    fclose(temp);

    if(isUpdated){
        remove(DATA_FILE);
        rename("temp.csv", DATA_FILE);
        printf("U sucsefully updated the information about %d ID student!\n\n", updatedId);
    } else{
        remove("temp.csv");
        printf("THere is no student with %d ID.\n\n", updatedId);
    }
}

void search(){
    FILE *file = fopen(DATA_FILE, "r");
    if(file == NULL){
        printf("Error!\n");
        return;
    }

    struct Student s;
    bool isFound = false;

    int searchId;
    printf("You can find the information about the student through his/her ID: ");
    scanf("%d", &searchId);

    while(fscanf(file, " %[^;];%[^;];%d;%f\n", s.Name,s.Surname,&s.ID, &s.gpa) == 4){
        if(s.ID == searchId){
            printf("THe information about hte student:\n");
            printf("Name: %s\nSurname: %s\nID: %d\nGPA: %.2f\n", s.Name, s.Surname, s.ID, s.gpa);
            isFound = true;
            break;
        }
    }

    if(isFound == false){
        printf("There is no student with such ID.\n\n");
    }

    fclose(file);
}

void display(){
    FILE *file = fopen(DATA_FILE, "r");
    if(file == NULL){
        printf("Error!\n");
        return;
    }
    
    struct Student s;

    printf("\tStudent List\n");
    printf("%-12s %-12s %-8s %-5s\n", "Name", "Surname", "ID", "GPA");

    while(fscanf(file, " %[^;];%[^;];%d;%f\n", s.Name, s.Surname, &s.ID, &s.gpa) == 4){
        printf("%-12s %-12s %-8d %-5.2f\n", s.Name, s.Surname, s.ID, s.gpa);
    }

    fclose(file);
}
