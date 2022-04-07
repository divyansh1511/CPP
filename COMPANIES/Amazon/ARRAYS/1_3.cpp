#include<bits/stdc++.h>
using namespace std;

int findduplicate(int arr[] , int n){
    bool arr1[n];
    memset(arr1 , false , sizeof(arr1));
    for (int i = 0; i < n; i++)
    {
        int a = arr[i];
        if (arr1[a] == true)
        {
            return a;
        }
        arr1[a] = true;
    }
    return -1;
}

int main(){

}