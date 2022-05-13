#include<bits/stdc++.h>
using namespace std;

int substring(string s){
    string a = "";
    int n = s.length();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto it = a.find(s[i]);
        if (it == string::npos)
        {
            a += s[i];
        }
        else
        {
            int b = a.length();
            ans = max(ans , b);
            a = s[i];
        }
    }
    int z = a.length();
    ans = max(ans , z);
    return ans;
}

int main(){
    
}