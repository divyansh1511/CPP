#include<bits/stdc++.h>
using namespace std;

string FractiontoDecimal(int num , int den){
    if (num == 0)
    {
        return "0";
    }
    string ans = "";
    ans += (num > 0 ) ^ (den > 0) ? "-" : "";
    long n = abs(num) , d = abs(den);
    ans += to_string(n/d);
    n = n%d;
    if (!n)
    {
        return ans;
    }
    ans += '.';
    unordered_map<long , int> mp;
    while (n)
    {
        n *= 10;
        ans += to_string(n/d);
        n = n%d;
        if (mp[n])
        {
            ans.insert(mp[n] , "(");
            ans += ")";
            break;
        }
        mp[n] = ans.size();
    }
    return ans;
}

int main(){

}