/* Reverse the elements in an array*/ 

# include <stdio.h> 

int main(){
    int a[5] = {1,2,3,4,5};  
    int i, temp ;  

    for (i = 0; i< 5/2; i++){
        temp = a[i];
        a[i] = a[5-1-i];
        a[5 - 1 - i] = temp; 
    }

    // Print the reversed array
    for (i = 0; i<5; i++){
        printf("%d ", a[i]);
    }

    return 0;  

} 

