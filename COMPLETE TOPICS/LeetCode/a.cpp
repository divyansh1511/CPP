#include<bits/stdc++.h>
using namespace std;

int boxes(string digits , vector<string> pass){
    vector<int> v(10 , 0);
    for (int i = 0; i < digits.length(); i++)
    {
        v[digits[i]-'0']++;
    }
    int ans = 0;
    for (int i = 0; i < pass.size(); i++)
    {
        vector<int> a = v;
        bool flag = true;
        for (int j = 0; j < pass[i].length(); j++)
        {
            a[pass[i][j] - '0']--;
            if (a[pass[i][j] - '0'] < 0)
            {
                flag = false;
                break;
            }
        }
        if(flag){
            ans++;
        }
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    cout<<boxes(s , v)<<endl;
}