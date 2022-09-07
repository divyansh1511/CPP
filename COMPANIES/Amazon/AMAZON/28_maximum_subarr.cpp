#include<bits/stdc++.h>
using namespace std;

int maxsubarr(int arr[] , int n){
    int sum = arr[0];
    int maxsum = arr[0];
    for (int i = 1; i < n; i++)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
        }
        maxsum = max(maxsum , sum);
    }
    return maxsum;
}

int main(){

}