//L - 2293
#include<bits/stdc++.h>
using namespace std;

int min_max_game(vector<int> &v){
    int n = v.size();
    while (n > 1)
    {
        n /= 2;
        for (int i = 0; i < n; i++)
        {
            if (i%2 == 0)
            {
                v[i] = min(v[2*i] , v[2*i+1]);
            }
            else
            {
                v[i] = max(v[2*i] , v[2*i+1]);
            }
        }
    }
    return v[0];
}

int main(){

}