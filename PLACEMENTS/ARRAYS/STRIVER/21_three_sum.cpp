#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(int arr[] , int n){
    sort(arr , arr+n);
    vector<vector<int>> res;
    for (int i = 0; i < n-2; i++)
    {
        if ((i > 0) && (arr[i] == arr[i-1]))
        {
            continue;
        }
        int l = i+1 , r = n-1;
        while (l < r)
        {
            int sum = arr[i]+arr[l]+arr[r];
            if (sum < 0)
            {
                l++;
            }
            else if (sum > 0)
            {
                r--;
            }
            else
            {
                res.push_back(vector<int>{arr[i] , arr[l] , arr[r]});
                while (l+1 < r && arr[l] == arr[l+1])
                {
                    l++;
                }
                while (l < r-1 && arr[r] == arr[r-1])
                {
                    r--;
                }
                l++;
                r--;
            }
        }
    }
    return res;
}

int main(){

}