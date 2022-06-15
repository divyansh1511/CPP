#include<bits/stdc++.h>
using namespace std;

vector<int> maximumunosorted(vector<int> a){
    int n = a.size();
    vector<int> v = a;
    sort(v.begin() , v.end());
    int mini = INT_MAX , maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != v[i])
        {
            mini = min(mini , i);
            maxi = max(maxi , i);
        }
    }
    if (mini == INT_MAX || maxi == INT_MIN)
    {
        return {-1};
    }
    return {mini , maxi};
}

int main(){

}