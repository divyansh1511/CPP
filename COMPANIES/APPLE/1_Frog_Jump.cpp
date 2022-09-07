#include<bits/stdc++.h>
using namespace std;

bool helper(vector<int> &v , int pos , int k){
    for (int i = pos+1; i < v.size(); i++)
    {
        int gap = v[i] - v[pos];
        if (gap < k-1)
        {
            continue;
        }
        if (gap > k+1)
        {
            return false;
        }
        if (helper(v , i , gap))
        {
            return true;
        }
    }
    return pos == v.size()-1;
}

bool frongjump(vector<int> &v){
    return helper(v , 0 , 0);
}

int main(){

}