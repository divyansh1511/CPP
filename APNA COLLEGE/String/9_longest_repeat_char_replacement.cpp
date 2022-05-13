#include<bits/stdc++.h>
using namespace std;

int longrepeated(string s , int k){
    int res = 0 , mx = 0;
    unordered_map<int , int> mp;
    for (int i = 0; i < s.length(); i++)
    {
        mx = max(mx , ++mp[s[i]]);
        if (res - mx < k)
        {
            res++;
        }
        else
        {
            mp[s[i-res]]--;
        }
    }
    return res;
}

int main(){

}