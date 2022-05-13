#include<bits/stdc++.h>
using namespace std;

string LCP(vector<string> &v){
    int n = v.size();
    string a = v[0];
    string b = v[n-1];
    string ans = "";
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == b[i])
        {
            ans += a[i];
        }
        else
        {
            break;
        }
    }
    return ans;
}

int main(){

}