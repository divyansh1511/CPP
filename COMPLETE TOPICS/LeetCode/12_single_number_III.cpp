#include<bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int> &nums){
    long a = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        a ^= nums[i];
    }
    a &= -a;
    int x = 0 , y = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (a & nums[i])
        {
            x ^= nums[i];
        }
        else
        {
            y ^= nums[i];
        }
    }
    return {x , y};
}

int main(){

}