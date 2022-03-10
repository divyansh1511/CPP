#include<bits/stdc++.h>
using namespace std;

int bulbs(vector<int> a){
    int n = a.size();
    int k = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (k = a[i])
        {
            if (k == 0)
            {
                k = 1;
            }
            else
            {
                k = 0;
            }
            ans++;
        }
    }
    return ans;
}

int main(){

}