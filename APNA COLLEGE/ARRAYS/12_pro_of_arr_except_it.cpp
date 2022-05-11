#include<bits/stdc++.h>
using namespace std;

vector<int> pro_of_arr(int arr[] , int n){
    vector<int> v(n);
    int pre = 1;
    for (int i = 0; i < n; i++)
    {
        v[i] = pre;
        pre *= arr[i];
    }
    int pos = 1;
    for (int i = n-1; i >= 0; i--)
    {
        v[i] *= pos;
        pos *= arr[i];
    }
    return v;
}

int main(){

}