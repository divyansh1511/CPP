#include<bits/stdc++.h>
using namespace std;

int deleteearn(vector<int> nums){
    int n = 10001;
    vector<int> v(n , 0);
    for(auto it : nums){
        v[it] += it;
    }
    int taki = 0 , st = 0;
    for (int i = 0; i < n; i++)
    {
        int t1 = st + v[i];
        int t2 = max(taki , st);
        taki = t1;
        st = t2;
    }
    return max(taki , st);
}

int main(){

}