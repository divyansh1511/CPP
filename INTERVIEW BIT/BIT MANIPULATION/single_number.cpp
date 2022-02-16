#include<bits/stdc++.h>
using namespace std;

int single_number(int arr[] , int n){
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        a = a^arr[i];
    }
    return a;
}

int main(){
    int arr[] = {1,2,1,3,2};
    cout<<single_number(arr , 5)<<endl;
}