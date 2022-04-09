#include<bits/stdc++.h>
using namespace std;

int single_number_2(vector<int> arr , int n){
    int ones = 0;
    int twos = 0;
    for (auto it : arr)
    {
        ones = (ones^it) & (~twos);
        twos = (twos^it) & (~ones); 
    }
    return ones;
}

int main(){

}