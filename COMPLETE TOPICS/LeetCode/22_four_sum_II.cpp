#include<bits/stdc++.h>
using namespace std;

int four_sum_2(vector<int> nums1 , vector<int> nums2 , vector<int> nums3 , vector<int> nums4){
    int n = nums1.size();
    int c = 0;
    unordered_map<int,int> mp;
    for(auto it1 : nums1){
        for(auto it2 : nums2){
            mp[it1+it2]++;
        }
    }
    for(auto it3 : nums3){
        for(auto it4 : nums4){
            if (mp.find(0-it3-it4) != mp.end())
            {
                c += mp[0-it3-it4];
            }
        }
    }
    return c;
}

int main(){

}