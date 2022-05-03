#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int> &v, int k)
{
    int res = 0;
    int n = v.size();
    for (int i = n-k; i <n ; i++)
    {
        res += v[i];
    }
    int s = res;
    for (int i = 0; i < k; i++)
    {
        s -= v[i];
        s += v[i];
        res = max(res , s);
    }
    return res;
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,1};
    int k = 3;
    cout<<maxScore(arr , k)<<endl;
}