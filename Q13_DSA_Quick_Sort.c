// Perform the Quick sort on the function as: 
# include <stdio.h> 

// Function to swap the 2 elements as: 
void swap(int *a, int *b){
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

// Partition Function works as: 
int partition(int arr[], int low, int high){
    int pivot = arr[high]; 
    int i = low - i; 

    for (int j = low; j < high; j++){
        if (arr[j] < pivot){
            i++; 
            swap(&arr[i], &arr[j]); 
        }
    }
    swap(&arr[i+1], &arr[high]); 
    return i+1; 
}

// Quick Sort Function working as: 
void quickSort(int arr[], int low, int high){
    if (low < high){
        int pi = partition(arr, low, high); 

        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi+1, high); 
    }
}

// Main Function 
int main(){
    int arr[100], n, i; 

    printf("Enter number of elements: "); 
    scanf("%d", &n); 

    printf("Enter %d elements:\n", n); 
    for(i=0; i < n; i++){
        scanf("%d", &arr[i]); 
    }

    quickSort(arr, 0, n-1); 
    printf("Sorted Array:\n"); 
    for(i  = 0; i<n; i++){
        printf("%d", arr[i]); 
    }

    return 0; 
}