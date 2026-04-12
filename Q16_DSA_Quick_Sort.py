# The implementation of the quick sort will be done as: 

def quick_sort(arr): 
    if len(arr) <= 1:
        return arr 
    
    pivot = arr[-1] 
    left = [] 
    right = [] 

    for i in range(len(arr) - 1): 
        if arr[i] < pivot: 
            left.append(arr[i]) 

        else: 
            right.append(arr[i]) 

    return quick_sort(left) + [pivot] + quick_sort(right) 

arr = list(map(int, input("Enter numbers separated by space: ").split()))

sorted_arr = quick_sort(arr)

print("Sorted array:", sorted_arr) 