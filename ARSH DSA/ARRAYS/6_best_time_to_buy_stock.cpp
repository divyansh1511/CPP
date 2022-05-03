#include<bits/stdc++.h>
using namespace std;

int besttime(vector<int> v){
    int minimum = INT_MAX;
    int maximum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        minimum = min(minimum , v[i]);
        maximum = max(maximum , v[i]-minimum);
    }
    return maximum;
}

int main(){

}