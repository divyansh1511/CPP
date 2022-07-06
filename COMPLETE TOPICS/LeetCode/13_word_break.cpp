#include<bits/stdc++.h>
using namespace std;

bool wordBreak(string s , vector<string> &v){
    vector<bool> dp(s.length() + 1 , false);
    dp[0] = true;
    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((dp[j]) && find(v.begin() , v.end() , s.substr(j , i-j)) != v.end())
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