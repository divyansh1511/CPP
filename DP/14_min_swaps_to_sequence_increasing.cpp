#include<bits/stdc++.h>
using namespace std;

int minswaps(vector<int> v1 , vector<int> v2){
    int n = v1.size();
    vector<int> noswaps(n , 0);
    vector<int> swaps(n , 1);
    for (int i = 1; i < n; i++)
    {
        swaps[i] = noswaps[i] = n;
        if (v1[i] > v1[i-1] && v2[i] > v2[i-1])
        {
            noswaps[i] = noswaps[i-1];
            swaps[i] = swaps[i-1] + 1;
        }
        if (v1[i] > v2[i-1] && v2[i] > v1[i-1])
        {
            swaps[i] = min(swaps[i] , noswaps[i-1]+1);
            noswaps[i] = min(noswaps[i] , swaps[i-1]);
        }
    }
    return min(swaps[n-1] , noswaps[n-1]);
}

int main(){

}