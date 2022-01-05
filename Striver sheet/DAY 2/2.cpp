#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> v){
    vector<vector<int>> ans;
    if(v.size() == 0){
        return ans;
    }
    sort(v.begin() , v.end());
    ans.push_back(v[0]);
    int j = 0;
    for(int i = 0;i<v.size();i++){
        if(ans[j][1] >= v[i][0]){
            ans[j][1] = max(ans[j][1] , v[i][1]);
        }
        else{
            j++;
            ans.push_back(v[i]);
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> v = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans = merge(v);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
}