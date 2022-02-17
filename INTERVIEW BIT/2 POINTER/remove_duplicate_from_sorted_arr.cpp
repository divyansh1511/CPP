#include<bits/stdc++.h>
using namespace std;

int removeduplicate(vector<int> &arr){
    int n = arr.size();
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (i < n-1 && arr[i] == arr[i+1])
        {
            continue;
        }
        else
        {
            arr[c] = arr[i];
            c++;
        }
    }
    return c;
}

int main(){
    vector<int> arr = {5,5,1,2,2,3,3};
    int n = removeduplicate(arr);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}