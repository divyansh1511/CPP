#include<bits/stdc++.h>
using namespace std;

int micetohole(vector<int> &a , vector<int> &b){
    sort(a.begin() , a.end());
    sort(b.begin() , b.end());
    int ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        ans = max(ans , abs(a[i] - b[i]));
    }
    return ans;
}

int main(){

}