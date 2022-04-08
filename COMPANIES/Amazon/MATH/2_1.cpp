#include<bits/stdc++.h>
using namespace std;

int titletoval(string s){
    int n = s.length();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += pow(26 , n-i-1)*(s[i]-'A'+1);
    }
    return ans;
}

int main(){

}