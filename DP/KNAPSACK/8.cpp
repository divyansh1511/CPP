#include<bits/stdc++.h>
using namespace std;

int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    int n = ages.size();
    vector<int> dp(n);
    vector<pair<int,int>> v(n , {0,0});
    for(int i=0;i<n;i++){
        v[i].first = ages[i];
        v[i].second = scores[i];
    }
    sort(v.begin() , v.end());
    int tt = 0;
    for(int i=0;i<n;i++){
        dp[i] = v[i].second;
        for(int j=i-1;j>=0;j--){
            if(v[i].second >= v[j].second){
                dp[i] = max(dp[i] , dp[j]+v[i].second);
            }
        }
        tt = max(tt , dp[i]);
    }
    return tt;
}

int main(){

}