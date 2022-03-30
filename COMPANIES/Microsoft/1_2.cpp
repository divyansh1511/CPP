#include<bits/stdc++.h>
using namespace std;

int findduplicate(int arr[] , int n){
    vector<int> v(n+1 , false);
    for (int i = 0; i < n; i++)
    {
        int a = arr[i];
        if (v[a] == true)
        {
            return a;
        }
        arr[a] = true;
    }
    return -1;
}

int main(){
    int arr[] = {2,2,5,7,8,1};
    cout<<findduplicate(arr , 6)<<endl;
}