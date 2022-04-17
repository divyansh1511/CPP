#include<bits/stdc++.h>
using namespace std;

vector<int> repandmis(vector<int> &v){
    long long int sum = 0;
    long long int squaresum = 0;
    long long int n = v.size();
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        sum -= (i+1);
        squaresum += v[i]*v[i];
        squaresum -= (i+1)*(i+1);
    }
    squaresum /= sum;
    int a = (int)(squaresum + sum)/2;
    int b = squaresum - a;
    vector<int> ans;
    ans.push_back(a);
    ans.push_back(b);
    return ans;
}

int main(){

}