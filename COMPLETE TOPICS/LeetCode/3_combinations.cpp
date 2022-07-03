#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> combinations(int n , int k){
    vector<vector<int>> ans;
    int i = 0;
    vector<int> v(k , 0);
    while (i >= 0)
    {
        v[i]++;
        if (v[i] > n)
        {
            i--;
        }
        else if (i == k-1)
        {
            ans.push_back(v);
        }
        else
        {
            i++;
            v[i] = v[i-1];
        }
    }
    return ans;
}

int main(){

}