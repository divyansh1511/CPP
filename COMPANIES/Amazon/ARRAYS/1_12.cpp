#include<bits/stdc++.h>
using namespace std;

vector<int> nextpermuatation(vector<int> v){
    int k,l;
    int n = v.size();
    for (k = n-2; k >= 0; k--)
    {
        if (v[k+1] > v[k])
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
    return v;
}

int main(){

}