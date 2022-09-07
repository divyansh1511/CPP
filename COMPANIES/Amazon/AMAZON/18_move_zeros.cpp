#include<bits/stdc++.h>
using namespace std;

void moveszero(int arr[] , int n){
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            arr[j] = arr[i];
            j++;
        }
    }
    for (j; j < n; j++)
    {
        arr[j] = 0;
    }
}

int main(){
    
}