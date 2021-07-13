#include<iostream>
using namespace std;

int minele(int arr[] , int n){
    int min = INT16_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int maxele(int arr[] , int n){
    int max = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int main(){
    int arr[] = {4,6,7,2,9};
    cout<<minele(arr , 5)<<endl;
    cout<<maxele(arr , 5)<<endl;
}