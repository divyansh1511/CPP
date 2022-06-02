#include<bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>> &a , int n){
    int left = 0 , right = n-1;
    while (left < right)
    {
        if (a[left][right] == 1)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    int ans = left;
    for (int i = 0; i < n; i++)
    {
        if (i != ans)
        {
            if (a[ans][i] == 1 || a[i][ans] == 0)
            {
                return -1;
            }
        }
    }
    return ans;
}

int main(){

}