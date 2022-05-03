#include<bits/stdc++.h>
using namespace std;

int findDuplicate(int arr[] , int n){
    vector<int> v(n, -1);
    for (int i = 0; i < n; i++)
    {
        int a = arr[i];
        if (v[a] != -1)
        {
            return a;
        }
    }
    return -1;
}

int main(){

}