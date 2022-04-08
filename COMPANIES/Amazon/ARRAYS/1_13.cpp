#include<bits/stdc++.h>
using namespace std;

vector<int> wavearr(vector<int> arr , int n){
    sort(arr.begin() , arr.end());
    for (int i = 0; i < n; i++)
    {
        if (i == n-1)
        {
            break;
        }
        swap(arr[i] , arr[i+1]);
    }
    return arr;    
}

int main(){

}