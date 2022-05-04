#include<bits/stdc++.h>
using namespace std;

int minmoves(vector<int> v){
    int n = v.size();
    int sum = v[0];
    int mn = v[0];
    for (int i = 0; i < n; i++)
    {
        mn = max(mn , v[i]);
        sum += v[i];
    }
    return sum - long(mn) * long(n);
}

int main(){

}