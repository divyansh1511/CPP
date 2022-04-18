#include<bits/stdc++.h>
using namespace std;

int trappingRainWater(vector<int> height){
    int n = height.size();
    int ml = 0 , mr = 0;
    int lo = 0 , hi = n-1;
    int ans = 0;
    while (lo <= hi)
    {
        if (height[lo] < height[hi])
        {
            if (height[lo] > ml)
            {
                ml = height[lo];
            }
            else
            {
                ans += (ml-height[lo]);
            }
            lo++;
        }
        else
        {
            if (height[hi] > mr)
            {
                mr = height[hi];
            }
            else
            {
                ans += (mr - height[hi]);
            }
            hi--;
        }
    }
    return ans;
}

int main(){

}