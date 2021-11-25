#include<bits/stdc++.h>
using namespace std;

int longestsubstr(string st){
    unordered_set<char> s;
    int i = 0 , j = 0 , n = st.length() , ans = 0;
    while (i < n && j < n)
    {
        if (s.find(st[j]) == s.end())
        {
            s.insert(st[j++]);
            ans = max(ans , j - i);
        }
        else
        {
            s.erase(st[i++]);
        }
    }
    return ans;
}

int main(){
    cout<<longestsubstr("abcabcbb")<<endl;
}