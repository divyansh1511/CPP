#include<bits/stdc++.h>
using namespace std;

bool wordbreak(string s , vector<string> dict){
    vector<bool> dp(s.size()+1 , false);
    dp[0] = true;
    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] && find(dict.begin() , dict.end() , s.substr(j , i-j)) != dict.end())
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