#include<bits/stdc++.h>
using namespace std;

void nextpermu(vector<int> &v){
    int k , l;
    int n = v.size();
    for (k = n-2; k >= 0; k--)
    {
        if (v[k] < v[k+1])
        {
            break;
        }
    }
    if (k < 0)
    {
        reverse(v.begin() , v.end());
    }
    else
    {
        for (l = n-1; l >= k; l--)
        {
            if (v[l] > v[k])
            {
                break;
            }
        }
        swap(v[l] , v[k]);
        reverse(v.begin()+k+1 , v.end());
    }
}

int main(){
    vector<int> v = {1,2,3};
    nextpermu(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
}