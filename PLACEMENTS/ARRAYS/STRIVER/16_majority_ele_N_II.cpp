#include<bits/stdc++.h>
using namespace std;

vector<int> majorityele(vector<int> v , int n){
    int cnt1 = 0 , cnt2 = 0 , a = 0 , b = 1;
    for(auto it : v){
        if (it == a)
        {
            cnt1++;
        }
        else if (it == b)
        {
            cnt2++;
        }
        else if (cnt1 == 0)
        {
            a = n;
            cnt1 = 1;
        }
        else if (cnt2 == 0)
        {
            b = n;
            cnt2 = 1;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = cnt2 = 0;
    for(auto it : v){
        if (it == a)
        {
            cnt1++;
        }
        if (it == b)
        {
            cnt2++;
        }
    }
    vector<int> ans;
    if (cnt1 > n/3)
    {
        ans.push_back(a);
    }
    if (cnt2 > n/3)
    {
        ans.push_back(b);
    }
    return ans;
}

int main(){

}