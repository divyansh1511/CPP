#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    for (int i = 0; i < nums1.size(); i++)
    {
        int a;
        int j;
        for (j = 0; j < nums2.size(); j++)
        {
            if (nums1[i] == nums2[j])
            {
                a = nums2[j];
                break;
            }
            
        }
        j++;
        bool flag = true;
        for (j; j < nums2.size(); j++)
        {
            if (nums2[j] > a)
            {
                ans.push_back(nums2[j]);
                flag = false;
                break;
            }
        }
        if (flag == true)
        {
            ans.push_back(-1);
        }
    }
    return ans;
}

vector<int> nextGreaterElement1(vector<int>& nums1, vector<int>& nums2) {
    stack<int> s;
    unordered_map<int, int> m;
    for (int n : nums2) {
        while (s.size() && s.top() < n) {
            m[s.top()] = n;
            s.pop();
        }
        s.push(n);
    }
    vector<int> ans;
    for (int n : nums1) ans.push_back(m.count(n) ? m[n] : -1);
    return ans;
}

int main(){
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    vector<int> v = nextGreaterElement1(nums1 , nums2);
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }    
}