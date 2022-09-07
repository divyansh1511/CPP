#include<bits/stdc++.h>
using namespace std;

void helper(vector<int> v , int st , vector<vector<int>> &ans){
    if (st > v.size())
    {
        ans.push_back(v);
        return;
    }
    for (int i = st; i < v.size(); i++)
    {
        swap(v[st] , v[i]);
        helper(v , st+1 , ans);
        swap(v[i] , v[st]);
    }
}

vector<vector<int>> permutations(vector<int> v){
    vector<vector<int>> ans;
    helper(v , 0 , ans);
    return ans;
}

int main(){

}