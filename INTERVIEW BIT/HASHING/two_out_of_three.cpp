#include<bits/stdc++.h>
using namespace std;

vector<int> two_out_of_three(vector<int> a , vector<int> b , vector<int> c){
    map<int , set<int>> mp;
    for (int i = 0; i < a.size(); i++)
    {
        mp[a[i]].insert(0);
    }
    for (int i = 0; i < b.size(); i++)
    {
        mp[b[i]].insert(1);
    }
    for (int i = 0; i < c.size(); i++)
    {
        mp[c[i]].insert(2);
    }
    vector<int> ans;
    for(auto it : mp){
        if (it.second.size() > 1)
        {
            ans.push_back(it.first);
        }
    }
    return ans;
}

int main(){

}