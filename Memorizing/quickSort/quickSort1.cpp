/* C++ implementation of QuickSort */
#include <bits/stdc++.h> 
using namespace std;  
  
// A utility function to swap two elements  
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
  
  /* Function to print an array */
void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */
int partition (int arr[], int low, int high)  {
    int pivot = arr[high]; //Choose last element as pivot
    cout<<"Pivot: "<<pivot<<"\n";
    int i = low-1;//index of smaller number

    for(int j = low; j<=high-1; j++){//run through array left to right
        if(arr[j]<pivot){//if current element smaller than pivot
            i++;//increment smallest element index
            cout<< "Swap1: ";
            printArray(arr, 6);
            swap(&arr[i], &arr[j]);
            cout<< "Swap2: ";
            printArray(arr, 6);
        }
    }
    cout<< "1: ";
    printArray(arr, 6);
    swap(&arr[i+1], &arr[high]);
    cout<< "2: ";
    printArray(arr, 6);
    
    return i+1;
}

/* The main function that implements QuickSort  
arr[] --> Array to be sorted,  
low --> Starting index,  
high --> Ending index */
void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi = partition(arr, low, high);//get partitioning index

        //sort each partition separately
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}  

  
// Driver Code 
int main()  
{  
    int arr[] = {10, 5, 8, 9, 1, 7};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    quickSort(arr, 0, n - 1);  
    cout << "Sorted array: \n";  
    printArray(arr, n);  
    return 0;  
}  