
# include <stdio.h> 
int main(){ 
    int r, c, key;

    printf("Enter rows and columns: "); 
    scanf("%d %d", &r, &c); 

    int matrix[r][c]; 

    printf("Enter thesorted matrix elements: "); 

    scanf("%d", &key); 

    int low = 0;
    int high =  r *c - 1; 
    int found = 0;  
    
    while(low <= high)
    {
        int mid = (low + high) / 2;

        int row = mid / c;
        int col = mid % c;

        if(matrix[row][col] == key)
        {
            printf("Element found at position (%d, %d)", row, col);
            found = 1;
            break;
        }
        else if(matrix[row][col] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if(!found)
        printf("Element not found");

    return 0;


    
}