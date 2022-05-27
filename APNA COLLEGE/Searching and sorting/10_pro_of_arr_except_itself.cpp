#include<bits/stdc++.h>
using namespace std;

void product(int arr[] , int n){
    int pro = 1;
    vector<int> v(n , 1);
    for (int i = 0; i < n; i++)
    {
        v[i] = pro;
        pro *= arr[i];
    }
    pro = 1;
    for (int i = n-1; i >= 0; i--)
    {
        v[i] *= pro;
        pro *= arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
}

int main(){

}