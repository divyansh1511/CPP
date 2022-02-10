#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        map<int , int> mp;
        for (int i = 0; i < 2*n; i++)
        {
            int a;
            cin>>a;
            mp[a]++;
        }
        for (int i = 0; i <= n+1; i++)
        {
            if (mp[i] == 0)
            {
                cout<<"YES"<<endl;
                break;
            }
            if(mp[i] == 1)
            {
                cout<<"NO"<<endl;
                break;
            }
        }
    }
}