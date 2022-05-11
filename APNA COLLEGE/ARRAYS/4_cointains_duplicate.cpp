#include<bits/stdc++.h>
using namespace std;

int containdupli(int arr[] , int n){
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);   
    }
    return s.size() == n;
}

int main(){

}