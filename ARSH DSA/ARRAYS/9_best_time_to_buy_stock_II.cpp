#include<bits/stdc++.h>
using namespace std;

int besttime(int arr[] , int n){
    int sum = 0;
    for (int i = 0; i < n-1; i++)
    {
        if (arr[i] > arr[i+1])
        {
            continue;
        }
        else
        {
            sum += (arr[i+1] - arr[i]);
        }
    }
    return sum;
}

int main(){

}