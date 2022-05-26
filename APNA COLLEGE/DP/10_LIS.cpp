#include<bits/stdc++.h>
using namespace std;

int LIS(vector<int> nums){
    vector<int> ans;
    for(auto it : nums){
        if (ans.empty() || ans[ans.size() - 1] < it)
        {
            ans.push_back(it);
        }
        else
        {
            auto x = lower_bound(ans.begin() , ans.end() , it);
            *x = it;
        }
    }
    return ans.size();
}

int main(){

}