#include<bits/stdc++.h>
using namespace std;

int number_of_1_bits(int A){
    int count = 0;
    while (A)
    {
        if (A&1)
        {
            count++;
        }
        A >>= 1;
    }
    return count;
}

int main(){
    cout<<number_of_1_bits(3)<<endl;
}