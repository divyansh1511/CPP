#include<bits/stdc++.h>
using namespace std;

int maxpoints(vector<vector<int>> points){
    int n = points.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_map<string , int> mp;
        int dup = 1;
        for (int j = i+1; j < n; j++)
        {
            if (points[j][0] == points[i][0] && points[j][1] == points[i][1])
            {
                dup++;
            }
            else
            {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int g = __gcd(dx , dy);
                mp[to_string(dx/g) + "_" + to_string(dy/g)]++;
            }
        }
        ans = max(ans , dup);
        for(auto it : mp){
            ans = max(ans , it.second+dup);
        }
    }
    return ans;
}

int main(){

}