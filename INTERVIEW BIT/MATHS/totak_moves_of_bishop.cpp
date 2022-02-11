#include<bits/stdc++.h>
using namespace std;

int moves(int A , int B){
    int ans = min(8 - B , A-1) + min(A-1 , B-1) + min(B-1 , 8-A) + min(8-A , 8-B);
    return ans;
}

int main(){
    cout<<moves(4 , 4)<<endl;
}