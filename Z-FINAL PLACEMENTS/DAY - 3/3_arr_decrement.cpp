#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int a[n];
        int b[n];
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin>>b[i];
        }
        int d = a[0] - b[0];
        if (d > 0)
        {
            for (int i = 0; i < n; i++)
            {
                a[i] = a[i]-d;
                if (a[i] < 0)
                {
                    a[i] = 0;
                }
            }
        }
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                cout<<"NO"<<endl;
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout<<"YES"<<endl;
        }
    }
    
}