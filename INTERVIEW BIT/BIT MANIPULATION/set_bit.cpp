#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n , p;
        cin>>n>>p;
        int a = 1;
        for(int i=0;i<p;i++){
            a <<= 1;
        }
        int ans = (n | a);
        cout<<ans<<endl;
    }
    return 0;
}