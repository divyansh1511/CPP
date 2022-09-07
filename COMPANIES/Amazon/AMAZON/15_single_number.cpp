#include<bits/stdc++.h>
using namespace std;

int single_number(int arr[] , int n){
    int xorr = arr[0];
    for (int i = 1; i < n; i++)
    {
        xorr ^= arr[i];
    }
    return xorr;
}

int main(){

}