#include<bits/stdc++.h>
using namespace std;

vector<int> repeatandmissing(vector<int> v){
    int sum = 0;
    int squaresum = 0;
    int temp;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
        sum -= (i+1);
        squaresum += v[i] * v[i];
        squaresum -= (i+1) * (i+1);
    }
    squaresum /= sum;
    int a = (squaresum+sum)/2;
    int b = squaresum - a;
    vector<int> ans;
    ans.push_back(a);
    ans.push_back(b);
    return ans;
}

int main(){

}