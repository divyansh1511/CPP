#include<bits/stdc++.h>
using namespace std;

int climbstairs(int n){
    if (n <= 2)
    {
        return n;
    }
    int arr[n];
    arr[0] = 1;
    arr[1] = 2;
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n-1];
}

int main(){

}