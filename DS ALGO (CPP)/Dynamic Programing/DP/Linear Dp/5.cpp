#include<bits/stdc++.h>
using namespace std;

int houserobber(int arr[] , int n){
    vector<int> f(n , 0);
    f[0] = arr[0];
    f[1] = max(arr[0] , arr[1]);
    for (int i = 2; i < n; i++)
    {
        f[i] = max(f[i-2] + arr[i] , f[i-1]);
    }
    return f[n-1];
}

int main(){

}