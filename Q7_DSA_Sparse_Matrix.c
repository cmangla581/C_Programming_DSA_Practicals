// Here, we will be forming the sparse matric and also include the max ,min, second max and second min 

# include <stdio.h>  
# include <limits.h> 

int main(){

    int r, c; 

    printf("Enter rows and columns: "); 
    scanf("%d %d", &r, &c); 

    int matrix[r][c]; 
    int i,j ; 

    int zeroCount = 0, nonZeroCount = 0; 
    int sum = 0; 

    int max = INT_MIN, min = INT_MAX ; 
    int secondMax = INT_MIN, secondMin = INT_MAX; 

    printf("Enter the matrix elements:\n"); 

    for (i=0; i < r; i++){ 
        for(j=0; j<c; j++){
            scanf("%d", &matrix[i][j]); 

            int val = matrix[i][j]; 

            sum += val;

            if(val == 0) 
               zeroCount++; 

            else  
                nonZeroCount++; 

            // Finding the max and second  max 
            if (val > max) 
            { 
                secondMax = max; 
                max = val; 

            }
            else if(val > secondMax && val  != max) 
            {
                secondMax = val; 

            }
            if (val < min)
            {
                secondMin = min; 
                min = val; 

            }
            else if(val < secondMin && val != min) 
            {
                secondMin = val; 

            }

        }
    }

    if (zeroCount > nonZeroCount) 
        printf("\nmatrix is sparse\n");     
    else
        printf("\nMatrix is not sparse\n");  

    printf("Sum of elements = %d\n", sum);
    printf("Maximum element = %d\n", max);
    printf("Second Maximum element = %d\n", secondMax);
    printf("Minimum element = %d\n", min);
    printf("Second Minimum element = %d\n", secondMin);

    return 0; 

}