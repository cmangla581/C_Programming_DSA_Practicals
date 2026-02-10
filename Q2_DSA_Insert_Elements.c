/* Insertion of elementsin the array*/ 

# include <stdio.h> 

int main(){
    int a[10] = {1,2,3,4,5};
    int n = 5;
    int pos,value;
    int i; 

    printf("Enter the position to insert (1 to %d): ", n+1);   
    scanf("%d", &pos);  

    printf(" Enter the value to insert: ");
    scanf("%d", &value); 

    // Shifting of the elements

    for (i = n; i>= pos ; i--){
        a[i] = a[i-1];
    }

    // Insert the elements 

    a[pos - 1] = value;
    n++; 

    // Print array 

    for (i = 0; i<n; i++){
        printf("%d ", a[i]);
    }

    return 0; 

}