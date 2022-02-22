#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> arr , int B){
    int odd = 0;
    int res = 0;
    int n = arr.size();
    vector<int> v(n+1 , 0);
    for (int i = 0; i < n; i++)
    {
        arr[odd]++;
        if (arr[i] & 1)
        {
            odd++;
        }
        if (odd >= B)
        {
            res += arr[odd-B];
        }        
    }
    return res;
}

int main(){

}