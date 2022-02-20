#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n , p;
        cin>>n>>p;
        int a = 1;
        for(int i=0;i<p;i++){
            a <<= 1;
        }
        a = ~a;
        int ans = (n & a);
        cout<<ans<<endl;
    }
    return 0;
}