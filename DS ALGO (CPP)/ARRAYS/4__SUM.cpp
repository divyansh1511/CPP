#include<bits/stdc++.h>
using namespace std;

//------------------------O(N^3)-------------------------------------//

vector<vector<int>> fourSum(vector<int> nums , int target){
    set<vector<int>> s;
    int n = nums.size();
    sort(nums.begin() , nums.end());
    int sum = 0;
    for(int i=0;i<n-3;i++){
        if(i > 0 && nums[i] == nums[i-1]){
            continue;
        }
        for(int j=i+1;j<n-2;j++){
            if(j > i+1 && nums[j] == nums[j-1]){
                continue;
            }
            int left = j+1 , right = n-1;
            while(left<right){
                sum = nums[i]+nums[j]+nums[left]+nums[right];
                if(sum > target){
                    right--;
                }
                else if(sum < target){
                    left++;
                }
                else{
                    vector<int> t;
                    t.push_back(nums[i]);
                    t.push_back(nums[j]);
                    t.push_back(nums[left]);
                    t.push_back(nums[right]);
                    s.insert(t);
                    left++;
                }
            }
        }
    }
    vector<vector<int>> ans;
    for(auto it : s){
        ans.push_back(it);
    }
    return ans;
}

//-------------------------------

vector<vector<int> > fourSum(vector<int> &num, int target){
    vector<vector<int> > vvi;
    int n = num.size();
    if(n < 4) return  vvi;    
    sort(num.begin(), num.end());        
    unordered_map<int, vector<pair<int, int>> > mp;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            mp[num[i]+num[j]].push_back(make_pair(i,j));
        }
    }
        
    for(int i = 0; i < n; i++){
        if(i>0 && num[i] == num[i-1]) continue;
        for(int j = i + 1; j < n; j++){
            if(j > i + 1 && num[j] == num[j-1]) continue;
            int res = target - num[i] - num[j];
            if(mp.count(res)){
                for(auto it = mp[res].begin(); it != mp[res].end(); it++){
                    int k = (*it).first, l = (*it).second;
                    if(k > j){ 
                        if(!vvi.empty() && num[i]==vvi.back()[0] && num[j]==vvi.back()[1] && num[k]==vvi.back()[2] && num[l] == vvi.back()[3]){
                            continue; 
                        }
                        vector<int> vi={num[i], num[j], num[k], num[l]};
                        vvi.push_back(vi);
                    }
                }
            }
        }
    }
    return vvi;
}

int main(){

}