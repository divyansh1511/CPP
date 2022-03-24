#include<bits/stdc++.h>
using namespace std;

//-------------------------------------ALL PERMUATATION---------------------------------//

void permute(vector<vector<int>> &ans , vector<int> &a , int idx){
    if (idx == a.size())
    {
        ans.push_back(a);
        return;
    }
    for (int i = idx; i < a.size(); i++)
    {
        swap(a[i] , a[idx]);
        permute(ans , a , idx+1);
        swap(a[i] , a[idx]);
    }
    return;
}

//------------------------------USING STL----------------------------------------//

void permuteSS(vector<vector<int>> &ans , vector<int> &a){
    sort(a.begin() , a.end());
    do
    {
        ans.push_back(a);
    } while (next_permutation(a.begin() , a.end()));
}

//------------------PERMUATION WITHOUT PRINTING DUPICATES------------------------//

void permutedup(vector<vector<int>> &ans , vector<int> &a , int idx){
    if (idx == a.size())
    {
        ans.push_back(a);
        return;
    }
    for (int i = idx; i < a.size(); i++)
    {
        if (i != idx && a[i] == a[idx])
        {
            continue;
        }
        swap(a[i] , a[idx]);
        permutedup(ans , a , idx+1);
        swap(a[i] , a[idx]);
    }
}



int main(){
    vector<int> a = {1,1,2};
    vector<vector<int>> ans;
    permutedup(ans , a , 0);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
}