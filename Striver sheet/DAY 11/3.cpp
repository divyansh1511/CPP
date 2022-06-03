#include<bits/stdc++.h>
using namespace std;

int findele(int arr[] , int n){
    int xor1 = arr[0];
    for (int i = 1; i < n; i++)
    {
        xor1 ^= arr[i];
    }
    return xor1;
}

int main(){

}