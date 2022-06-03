#include<bits/stdc++.h>
using namespace std;

bool wordBreak(string s , vector<string> v){
    vector<bool> dp(s.size()+1 , false);
    v[0] = true;
    for (int i = 1; i <= s.size() ; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] && find(v.begin() , v.end() , s.substr(i , j-i+1)) != v.end())
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp.back();
}

int main(){

}