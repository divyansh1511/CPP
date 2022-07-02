#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> v , int k , int mid){
    int cowcount = 1;
    int lastpos = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] - lastpos >= mid)
        {
            cowcount++;
            if (cowcount == k)
            {
                return true;
            }
            lastpos = v[i];
        }
    }
    return false;
}

int aggresivecows(vector<int> v , int k){
    sort(v.begin() , v.end());
    int s = 0;
    int maxi = -1;
    for (int i = 0; i < v.size(); i++)
    {
        maxi = max(maxi , v[i]);
    }
    int e = maxi;
    int ans = -1;
    int mid = s + (e-s)/2;
    while (s <= e)
    {
        if (isPossible(v , k , mid))
        {
            ans = mid;
            s = mid+1;
        }
        else
        {
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main(){

}