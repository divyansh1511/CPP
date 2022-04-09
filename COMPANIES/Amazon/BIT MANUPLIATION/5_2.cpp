#include<bits/stdc++.h>
using namespace std;

int singlenumber(int arr[] , int n){
    int a = arr[0];
    for (int i = 1; i < n; i++)
    {
        a ^= arr[i];
    }
    return a;
}

int main(){

}