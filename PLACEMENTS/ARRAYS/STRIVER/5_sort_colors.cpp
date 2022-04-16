#include<bits/stdc++.h>
using namespace std;

void sortcolors(vector<int> &v){
    int n = v.size();
    int zeros = 0 , ones = 0 , twos = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            zeros++;
        }
        else if (v[i] == 1)
        {
            ones++;
        }
        else
        {
            twos++;
        }
    }
    int i = 0;
    for (i = 0; i < zeros; i++)
    {
        v[i] = 0;
    }
    for (i; i < (zeros+ones); i++)
    {
        v[i] = 1;
    }
    for (i; i < n; i++)
    {
        v[i] = 2;
    }
}

int main(){
    vector<int> v = {1,2,2,1,0,2,1,0};
    sortcolors(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    
}