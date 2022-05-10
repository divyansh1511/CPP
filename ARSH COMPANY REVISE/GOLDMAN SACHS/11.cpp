#include<bits/stdc++.h>
using namespace std;

vector<int> missiandrepeat(vector<int> nums){
    int squaresum = 0;
    int sum = 0;
    int temp;
    for (int i = 0; i < nums.size(); i++)
    {
        temp = nums[i];
        sum += temp;
        sum -= (i+1);
        squaresum += (sum * sum);
        squaresum -= (i+1)*(i+1); 
    }
    squaresum /= sum;
    int a = (squaresum + sum)/2;
    int b = squaresum - a;
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    return v;
}

int main(){

}