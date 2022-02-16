#include<bits/stdc++.h>
using namespace std;

int single_number(int arr[] , int n){
    int ones = 0;
    int twos = 0;
    for (int i = 0; i < n; i++)
    {
        ones = (ones^arr[i]) & (~twos);
        twos = (twos^arr[i]) & (~ones);
    }
    return ones;
}

int main(){
    int arr[] = {2,2,2,9,3,3,3};
    cout<<single_number(arr , 7)<<endl;
}