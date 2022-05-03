#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> v){
    vector<vector<int>> ans;
    int n = v.size();
    sort(v.begin() , v.end());
    for (int i = 0; i < n-2; i++)
    {
        if (i > 0 && v[i] == v[i-1])
        {
            continue;
        }
        int a = i+1 , b = n-1;
        while (a < b)
        {
            int sum = v[i]+v[a]+v[b];
            if (sum < 0)
            {
                a++;
            }
            else if (sum > 0)
            {
                b--;
            }
            else
            {
                ans.push_back({v[i] , v[a] , v[b]});
                while (a+1 < b && v[a] == v[a+1])
                {
                    a++;
                }
                while (a < b-1 && v[b] == v[b-1])
                {
                    b--;
                }
            }
            a++;
            b--;
        }
    }
    return ans;
}

int main(){

}