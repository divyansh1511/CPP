#include<bits/stdc++.h>
using namespace std;

int removeduplicate(vector<int> v , int n){
    vector<int> ans;
    ans.push_back(v[0]);
    for (int i = 1; i < n; i++)
    {
        if (ans[ans.size() - 1] != v[i])
        {
            ans.push_back(v[i]);
        }
    }
    return ans.size();
}

int main(){

}