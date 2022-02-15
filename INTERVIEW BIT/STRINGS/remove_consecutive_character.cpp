#include<bits/stdc++.h>
using namespace std;

string removeduplicate(string s , int k){
    int count = 1;
    int n = s.length();
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] == s[i+1])
        {
            count++;
        }
        else
        {
            if(count == k){
                count = 1;
                continue;
            }
            ans += s[i];
            count = 1;
        }
    }
    return s;
}

int main(){

}