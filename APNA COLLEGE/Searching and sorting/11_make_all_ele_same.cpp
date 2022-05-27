#include<bits/stdc++.h>
using namespace std;

int costtomake(int arr[] , int n){
    int a;
    if (n%2 == 0)
    {
        a = (arr[n/2] + arr[(n-2)/2])/2;
    }
    else
    {
        a = arr[n/2];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs(arr[i] - a);
    }
    return ans;
}

int main(){

}