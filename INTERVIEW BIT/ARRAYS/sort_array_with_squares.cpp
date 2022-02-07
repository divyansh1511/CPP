#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> arr){
    int n = arr.size();
    int left = 0;
    int right = n-1;
    vector<int> ans(n);
    for (int i = n-1; i >= 0; i--)
    {
        if (abs(arr[left]) > abs(arr[right]))
        {
            ans[i] = arr[left]*arr[left];
            left++;
        }
        else
        {
            ans[i] = arr[right]*arr[right];
            right--;
        }
    }
    return ans;
}

int main(){

}