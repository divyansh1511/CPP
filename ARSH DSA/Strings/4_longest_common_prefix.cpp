#include<bits/stdc++.h>
using namespace std;

string LCP(vector<string> &str){
    int n = str.size();
    string ans = "";
    if (n == 0)
    {
        return ans;
    }
    sort(str.begin() , str.end());
    string a = str[0] , b = str[n-1];
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