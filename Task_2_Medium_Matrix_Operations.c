//Matrix
#include <stdio.h>
#include <string.h>

void addition(int row, int col, int arr1[row][col], int arr2[row][col], int add[row][col]);
void multiplication(int row, int col1, int row2, int col, int arr1[row][col1], int arr2[row2][col], int mult[row][col]);
void transposition(int row, int col, int arr[row][col], int trans[col][row]);

int main(){
    
    int a1,b1;
    printf("\nMatrix 1\nEnter the number of rows: ");
    scanf("%d", &a1);
    printf("Enter the number of columns: ");
    scanf("%d", &b1);

    int arr1[a1][b1];

    for(int i =0; i<a1; i++){
        for(int j=0; j<b1;j++){
            printf("Enter the element [%d][%d]: ",i+1,j+1);
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("\nMatrix 1:\n");
    for(int i =0; i<a1; i++){
        printf("[");
        for(int j = 0 ; j<b1; j++){
            printf(" %d", arr1[i][j]);
        }
        printf(" ]\n");
    }

    int a2,b2;
    printf("\nMatrix 2\nEnter the number of rows: ");
    scanf("%d", &a2);
    printf("Enter the number of columns: ");
    scanf("%d", &b2);

    int arr2[a2][b2];

    for(int i=0; i<a2;i++){
        for(int j = 0; j<b2;j++){
            printf("Enter the element [%d][%d]: ", i+1,j+1);
            scanf("%d", &arr2[i][j]);
        }
    }

    printf("\nMatrix 2:\n");
    for(int i=0;i<a2;i++){
        printf("[");
        for(int j =0; j<b2; j++){
            printf(" %d", arr2[i][j]);
        }
        printf(" ]\n");
    }

    while(1){
        printf("\nWhat do you want to do? [addition/multiplication/transposition/q to quit] or [add/mult/trans/q]: ");
        char answer[16];
        scanf("%15s", answer);

        if(strcmp(answer,"addition") == 0 || strcmp(answer,"add") == 0){
            if((a1 != a2) || (b1 != b2)){
                printf("The number of rows and columns of these two matrix must be the same! On the other hand, it will be an error.\n");
            } else{
                int add[a1][b1];
                printf("\nAddition of two arrays: \n");
                addition(a1,b1,arr1,arr2,add);
            }
        } else if(strcmp(answer,"multiplication") == 0 || strcmp(answer, "mult")== 0){
            if(b1 != a2){
                printf("You cant multiply these two matrix, if the columns of first matrix and rows of second one are not the same!\n");
            } else{
                int mult[a1][b2];
                printf("\nMultiplication of two arrays: \n");
                multiplication(a1,b1,a2,b2,arr1,arr2,mult);
            }
        } else if(strcmp(answer,"transposition")== 0 || strcmp(answer, "trans") == 0){
            printf("\nWhich of the two matrixes u want to transpose [1/2]?: ");
            int choice;
            scanf("%d", &choice);
            if(choice == 1){
                int trans_arr1[b1][a1];
                printf("\nTransposed Matrix 1:\n");
                transposition(a1,b1,arr1, trans_arr1);
            } else if(choice == 2){
                int trans_arr2[b2][a2];
                printf("\nTransposed Matrix 2:\n");
                transposition(a2,b2,arr2,trans_arr2);
            } else{
                printf("\nYou dont have so many matrixes!\n");
            }
        } else if(strcmp(answer,"q") ==0){
            printf("You are quiting.\n");
            return 0;
        } else{
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}

void addition(int row, int col, int arr1[row][col], int arr2[row][col], int add[row][col]){

    for(int i =0; i< row;i++){
    for(int j =0; j< col;j++){
        add[i][j]= arr1[i][j] + arr2[i][j];
        }
    }

    for(int i=0;i<row;i++){
        printf("[");
        for(int j =0; j<col; j++){
            printf(" %d", add[i][j]);
        }
        printf(" ]\n");
    }

}

void multiplication(int row, int col1, int row2, int col, int arr1[row][col1], int arr2[row2][col], int mult[row][col]){

    for(int i =0; i< row; i++){
        for(int j =0; j<col; j++){
            mult[i][j] = 0;
            for(int k =0; k<row2; k++){
                mult[i][j]+= arr1[i][k]*arr2[k][j];
            }
        }
    }

    for(int i=0; i< row; i++){
        printf("[");
        for(int j =0; j< col; j++){
            printf(" %d", mult[i][j]);
        }
        printf(" ]\n");
    }
}

void transposition(int row, int col, int arr[row][col], int trans[col][row]){
    for(int i=0; i<row; i++){
        for(int j=0; j< col; j++){
            trans[j][i] = arr[i][j];
        }
    }

    for(int i =0; i< col; i++){
        printf("[");
        for(int j =0; j< row; j++){
            printf(" %d", trans[i][j]);
        }
        printf(" ]\n");
    }
}
