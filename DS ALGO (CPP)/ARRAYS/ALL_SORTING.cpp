#include<bits/stdc++.h>
using namespace std;

//---------------------------bubble sort-----------------------//

void bubblesort(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (arr[j-1] > arr[j])
            {
                swap(arr[j-1] , arr[j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

//---------------------------Insertion sort---------------------//

void insertionSort(int arr[] , int n){
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i-1;
        while (j >=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

//-------------------------selection sort---------------------//

void selectionsort(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        int minindex = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[minindex])
            {
                minindex = j;
            }
        }
        swap(arr[minindex] , arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

//----------------------------merge sort------------------------//

void merge(int arr[] , int start , int mid , int end){
    int temp[end-start+1];
    int i = start , j = mid+1 , k = 0;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }
    while (j <= end)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int i = start; i <= end; i++)
    {
        arr[i] = temp[i-start];
    }
}

void mergesort(int arr[] , int start , int end){
    if (start > end)
    {
        return;
    }
    int mid = (start+end)/2;
    mergesort(arr , start , mid);
    mergesort(arr , mid+1 , end);
    merge(arr , start , mid , end);
}

//-----------------------------------quick sort-------------------------------//

int partition(int arr[] , int start , int end){
    int count = 0;
    int pivot = arr[start];
    for (int i = start+1; i <= end; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    int pivotele = start+count;
    swap(arr[pivotele] , arr[start]);
    int i = start , j = end;
    while (i < pivotele && j > pivotele)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotele && j > pivotele)
        {
            swap(arr[i++] , arr[j--]);
        }
    }
    return pivotele;
}

void quicksort(int arr[] , int start , int end){
    if (start > end)
    {
        return;
    }
    int p = partition(arr , start , end);
    quicksort(arr , start , p);
    quicksort(arr , p+1 , end);
}

int main(){
    int arr[] = {5,2,1,4,3};
}