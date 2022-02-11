#include<bits/stdc++.h>
using namespace std;

int uniquePathhelper(int a , int b){
    if (a < 0 || b < 0)
    {
        return 0;
    }
    else if (a == 0 || b == 0)
    {
        return 1;
    }
    else
    {
        return uniquePathhelper(a - 1 , b) + uniquePathhelper(a , b-1);
    }
}

int uniquePath(int a , int b){
    return uniquePathhelper(a-1 , b-1);
}

int main(){
    cout<<uniquePath(3 , 7)<<endl;
}