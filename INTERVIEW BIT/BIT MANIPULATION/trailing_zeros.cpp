#include<bits/stdc++.h>
using namespace std;

int trailing_zeros(int A){
    int count = 0;
    while (A)
    {
        if (A&1)
        {
            break;
        }
        count++;
        A >>= 1;
    }
    return count;
}

int main(){
    cout<<trailing_zeros(10)<<endl;
}