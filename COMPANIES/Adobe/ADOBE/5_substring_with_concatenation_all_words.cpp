#include<bits/stdc++.h>
using namespace std;

vector<int> substringwithallwords(string s , vector<string> words){
    vector<int> ans;
    int n = words.size();
    int m = words[0].length();
    if (s.length() < n*m)
    {
        return ans;
    }
    for (int i = 0; i < s.length()-n*m; i++)
    {
        unordered_map<string , int> mp;
        for (int j = 0; j < n; j++)
        {
            mp[words[j]]++;
        }
        int t;
        for (t = 0; t < n; t++)
        {
            string st = s.substr(i + t*m , m);
            if (mp.count(st) == 0)
            {
                break;
            }
            else
            {
                if (mp[st] != 0)
                {
                    mp[st]--;
                }
                else
                {
                    break;
                }
            }
        }
        if (t == n)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

int main(){

}