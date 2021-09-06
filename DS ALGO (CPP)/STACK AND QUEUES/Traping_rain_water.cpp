#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//-------------------------------------O(N) O(N)-----------------------------------//

int trap(vector<int> height){
    int n = height.size();
    int left[n];
    int right[n];
    int ml = left[0] = height[0];
    int mr = right[n-1] = height[n-1];
    for(int i=1;i<n;i++){
        if(height[i] > ml){
            ml = height[i];
            left[i] = ml;
        }
        else
        {
            left[i] = left[i-1];
        }
    }
    for(int i=n-2;i>=0;i--){
        if(height[i] > mr){
            mr = height[i];
            right[i] = mr;
        }
        else
        {
            right[i] = right[i+1];
        }
    }
    int s = 0;
    for(int i=0;i<n;i++){
        s += min(left[i] , right[i]) - height[i];
    }
    return s;
}

//---------------------------------------O(N) O(1)-----------------------------//

int solve(vector<int> height){
    int n = height.size();
    int low = 0;
    int high = n-1;
    int mi = 0;
    int ma = 0;
    int ans = 0;
    while (low <= high)
    {
        if (height[low] < height[high])
        {
            if (height[low] > mi)
            {
                mi = height[low];
            }
            else
            {
                ans = ans + mi - height[low];
            }
            low++;
        }
        else
        {
            if (height[high] > ma)
            {
                ma = height[high];
            }
            else
            {
                ans = ans + ma - height[high];
            }
            high--;
        }
    }
    return ans;
}

int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(height)<<endl;
    cout<<solve(height)<<endl;
}