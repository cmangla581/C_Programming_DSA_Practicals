// Write a C program to perform the bubble sort problem perfectly as: 

# include <stdio.h> 

int main(){

    int n, i, j, temp; 

    printf("Enter the number of elements:\n"); 
    scanf("%d", &n); 

    int arr[n]; 

    printf("Enter the %d elements:\n", n); 
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]); 

    }
    // Bubbel sort algorithm as: 

    for(i = 0; i < n-1; i++){
        for(j = 0; j<n - i - 1; j++){
            if (arr[j] > arr[j+1]){
                // Swap 
                temp  = arr[j]; 
                arr[j] = arr[j+1]; 
                arr[j+1] =  temp;
            }
        }
    } 
    printf("Sorted Array:\n"); 
    for(i = 0; i<n; i++){
        printf("%d ", arr[i]); 

    } 
    return 0; 

}