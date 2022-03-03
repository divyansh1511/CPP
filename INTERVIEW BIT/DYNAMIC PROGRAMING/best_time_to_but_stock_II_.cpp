#include<bits/stdc++.h>
using namespace std;

int solve(int arr[] , int n){
    if (n == 0)
    {
        return 0;
    }
    int sum = 0;
    for(int i=0;i<n;i++){
        if(arr[i] > arr[i+1]){
            continue;
        }
        else{
            sum += (arr[i+1] - arr[i]);
        }
    }
    return sum;
}

int main(){

}