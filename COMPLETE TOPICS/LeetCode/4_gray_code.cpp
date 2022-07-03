#include<bits/stdc++.h>
using namespace std;

vector<int> graycode(int n){
    vector<int> res;
    res.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        int prevlength = res.size();
        int mask = 1 << (i-1);
        for (int j = prevlength-1; j >= 0; j--)
        {
            res.push_back(mask+res[j]);
        }
    }
    return res;
}

int main(){

}