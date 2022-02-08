#include<bits/stdc++.h>
using namespace std;

int minsteps(vector<int> a , vector<int> b){
    int n = a.size();
    int ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (abs(a[i] - a[i+1]) <= abs(b[i] - b[i+1]))
        {
            ans += (abs(b[i] - b[i+1]));
        }
        else
        {
            ans += (abs(a[i] - a[i+1]));
        }
    }
    return ans;
}

int main(){

}