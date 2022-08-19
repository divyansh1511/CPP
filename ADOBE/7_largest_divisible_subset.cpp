#include<bits/stdc++.h>
using namespace std;

vector<int> largestdivisiblesubset(vector<int> arr){
    int n = arr.size();
    if(n <= 1){
        return arr;
    }
    sort(arr.begin() , arr.end());
    vector<int> dp(n,1) , hash(n);
    int maxi = 0;
    int lastelementindex = -1;
    for (int i = 1; i < n; i++)
    {
        hash[i] = i;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] % arr[j] == 0 && dp[i] < dp[j]+1)
            {
                dp[i] = dp[j]+1;
                hash[i] = j;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastelementindex = i;
        }
    }
    vector<int> ans;
    ans.push_back(arr[lastelementindex]);
    while (hash[lastelementindex] != lastelementindex)
    {
        lastelementindex = hash[lastelementindex];
        ans.push_back(arr[lastelementindex]);
    }
    reverse(ans.begin() , ans.end());
    return ans;
}

int main(){

}