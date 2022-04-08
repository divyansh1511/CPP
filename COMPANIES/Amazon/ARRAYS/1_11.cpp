#include<bits/stdc++.h>
using namespace std;

int max_distance(vector<int> v){
    if (v.size() == 0)
    {
        return 0;
    }
    vector<pair<int,int>> ans;
    for (int i = 0; i < v.size(); i++)
    {
        ans.push_back(make_pair(v[i] , i));
    }
    sort(v.begin() , v.end());
    int ans1 = 0;
    int n = v.size();
    int rmax = ans[n-1].second;
    for (int i = n-2; i >= 0; i++)
    {
        ans1 = max(ans1 , rmax-ans[i].second);
        rmax = max(rmax , ans[i].second);
    }
    return ans1;
}

int main(){

}