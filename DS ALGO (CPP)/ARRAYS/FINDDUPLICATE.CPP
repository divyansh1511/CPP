#include<iostream>
using namespace std;

int duplicate(int arr[] , int n){
    int a = INT16_MAX;
    int str[a];
    for (int i = 0; i < a; i++)
    {
        str[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        int j = arr[i];
        str[j]++;
        if (str[j] > 1)
        {
            return j;
        }
    }
    return -1;
}

int main(){
    int arr[] = {3,1,3,4,2};
    cout<<duplicate(arr , 5)<<endl;
}