//Task_1 Calculator
#include <stdio.h>
#include <stdbool.h>

int main(){
    float a,b;
    char c;
    float sum;

    while(true){
        printf("Enter the expression['q' to exit]: ");
        if(scanf("%f %c %f", &a, &c, &b) != 3){
            printf("Exitinq.\n");
            return 1;
        };

        switch(c){
            case '+':
                sum = a+b;
                break;

            case '-':
                sum = a-b;
                break;

            case '/':
            case ':':
                if(b==0){
                    printf("You can't divide number by zero!");
                    return 1;
                }
                else{
                    sum = a/b;
                }
                break;

            case '*':
                sum = a*b;
                break;

            default:
                printf("Invalid input!");
                return 1;
        }

        printf("=%.2f\n\n",sum);
    }

    return 0;
}
