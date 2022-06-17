#include<bits/stdc++.h>
using namespace std;

int uniquesubstring(string p){
    vector<int> c(26 , 0);
    int mx = 1;
    for (int i = 0; i < p.length(); i++)
    {
        if (i > 0 && (p[i] - p[i-1] == 1 || p[i-1]-p[i] == 25))
        {
            mx++;
        }
        else
        {
            mx = 1;
        }
        c[p[i]-'a'] = max(mx , c[p[i]-'a']);
    }
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        ans += c[i];
    }
    return ans;
}

int main(){

}