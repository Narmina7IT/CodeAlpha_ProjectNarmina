//Task_1 Calculator
#include <stdio.h>
#include <stdbool.h>

int main(){
    double a,b, result;
    char c;
    printf("\tSimple Calculator\n");

    while(true){

        printf("Enter the expression: ");

        if(scanf("%lf %c %lf", &a, &c, &b) != 3){

            int ch;
            while((ch = getchar()) != '\n' && ch != EOF);

            printf("You want to exit? Press y to exit: ");
            char answer;
            if(scanf(" %c", &answer) == 1 && (answer == 'y' || answer == 'Y')){
                printf("Exiting.\n");
                return 0;
            }

            continue;
        }

        switch(c){
            case '+':
                result = a+b;
                break;

            case '-':
                result = a-b;
                break;

            case '/':
            case ':':
                if(b==0){
                    printf("You can't divide number by zero!\n");
                    continue;
                }
                
                result = a/b;
                break;

            case '*':
                result = a*b;
                break;

            default:
                printf("Invalid input! Please try again.\n");
                continue;
        }

        if(result == (long)result){
            printf("=%ld\n\n", (long)result);
        } else{
            printf("=%.2lf\n\n",result);
        }
    }

    return 0;
}
