#include<bits/stdc++.h>
using namespace std;

bool static cmp(vector<int> a1 , vector<int> a2){
    return a1[0] < a2[0];
}

vector<vector<int>> mergeoverlapping(vector<vector<int>> v){
    sort(v.begin() , v.end() , cmp);
    vector<vector<int>> ans;
    ans.push_back(v[0]);
    for (int i = 0; i < v.size(); i++)
    {
        int n = ans.size();
        if (ans[n - 1][1] > v[i][0])
        {
            ans[n-1][1] = max(ans[n-1][1] , v[i][1]);
        }
        else
        {
            ans.push_back(v[i]);
        }
    }
    return ans;
}

int main(){

}