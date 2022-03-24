#include<bits/stdc++.h>
using namespace std;

vector<int> subarr(int arr[] , int n , int x){
    int start = 0 , end = 0;
    int minlength = n+1 , sum = 0;
    int startindex = 0;
    while (end < n)
    {
        sum += arr[end];
        while (sum > x)
        {
            if (end - start + 1 < minlength)
            {
                minlength = end - start + 1;
                startindex = start;
            }
            sum -= arr[start];
            start++;
        }
        end++;
    }
    vector<int> ans;
    if (minlength == n+1)
    {
        return ans;
    }
    for (int i = startindex; i < startindex+minlength; i++)
    {
        ans.push_back(arr[i]);
    }
    return ans;
}

int main(){
    int arr[] = {1,2,3,4,5};
    vector<int> v = subarr(arr , 5 , 6);
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
}