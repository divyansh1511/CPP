#include<bits/stdc++.h>
using namespace std;

vector<int> repeatedANDmissing(int arr[] , int n){
    vector<int> v(n , false);
    int a1 , b1;
    for (int i = 0; i < n; i++)
    {
        int a = arr[i];
        if (v[a] == true)
        {
            a1 = a;
        }
        v[a] = true;
    }
    for (int i = 0; i < n; i++)
    {
        if (v[arr[i]] == false)
        {
            b1 = arr[i];
            break;
        }
    }
    vector<int> ans;
    ans.push_back(a1);
    ans.push_back(b1);
    return ans;
}

int main(){

}