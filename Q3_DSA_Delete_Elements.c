/* Write a C Program  to delete the elements*/ 

# include <stdio.h> 

int main(){
    int a[5] = {1,2,3,4,5};
    int n = 5; 
    int pos , i; 

    printf("Enter the position to delete (1 to %d): ", n);
    scanf("%d", &pos);

    //  Shift elements to the left  
    for (i = pos; i<n-1; i++){
        a[i] = a[i+1];
    }

    n--; // Decrese array size 

    // Print updated array 
    for (i = 0; i<n; i++){
        printf("%d ", a[i]);
    }

    return 0; 
}