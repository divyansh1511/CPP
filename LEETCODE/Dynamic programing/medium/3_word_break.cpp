#include<bits/stdc++.h>
using namespace std;

bool wordbreak(string s , vector<string> words){
    vector<int> dp(s.size()+1 , false);
    for (int i = 1; i < s.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((dp[j]) && (find(words.begin() , words.end() , s.substr(j , i-j)) != words.end()))
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