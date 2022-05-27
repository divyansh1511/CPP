#include<bits/stdc++.h>
using namespace std;

void findDuplicate(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        arr[arr[i]%n] = arr[arr[i]%n] + n;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= n*2)
        {
            cout<<arr[i]<<" ";
        }
    }
}

int main(){

}