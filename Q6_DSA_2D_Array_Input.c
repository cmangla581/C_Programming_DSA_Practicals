/* Printing the 2D array using the */ 

# include <stdio.h> 

int main(){
    int rows, cols, i, j;
    int a[10][10]; 

    printf("Enter a number of rows and columns: ");
    scanf("%d %d", &rows, &cols);  

    printf("Enter the elements: \n"); 
    for (i = 0; i < rows; i++){
        for (j = 0; j < cols; j++){
            scanf("%d", &a[i][j]);
        }
    }

    printf("2D Array is: \n");
    for (i=0; i  < rows; i++){
        for (j=0; j<cols;  j++){
            printf("%d ", a[i][j]);
        }

        printf("\n"); 

    }

    return 0;  

}