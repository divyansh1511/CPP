#include<bits/stdc++.h>
using namespace std;

int maxsum(int arr[] , int n){
    int sum1 = arr[0];
    int sum2 = 0;
    int temp;
    for (int i = 1; i < n; i++)
    {
        temp = max(sum1 , sum2);
        sum1 = sum1 + arr[i];
        sum2 = temp;
    }
    return max(sum1 , sum2);
}

int main(){

}