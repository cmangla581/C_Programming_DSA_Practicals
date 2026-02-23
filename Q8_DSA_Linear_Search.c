
# include <stdio.h> 
int main(){
    int n, i, key, found = 0;  

    printf("Enter the size of array: "); 
    scanf("%d", &n); 

    int arr[n]; 

    printf("Enter %d elements:\n", n); 
    for(i=0; i<n; i++) 
           scanf("%d", &arr[i]);

    printf("Ener the elements to search: "); 
    scanf("%d", &key); 

    for(i=0; i<n; i++){
        if(arr[i]== key)
        {
            printf("element found at position %d", i+1); 
            found = 1; 
            break; 
        }
    }
    
    if (found == 0) 
        printf("Element not found"); 

    return 0; 

} 