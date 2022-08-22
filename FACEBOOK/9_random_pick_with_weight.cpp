#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> v;
    Solution(vector<int>& w) {
        for(int i=0;i<w.size();i++){
            if(v.empty()){
                v.push_back(w[i]);
            }
            else{
                v.push_back(w[i] + v.back());
            }
        }
    }
    
    int pickIndex() {
        int x = v.back();
        int ind = rand()%x;
        auto it = upper_bound(v.begin() , v.end() , ind);
        return it-v.begin();
    }
};

int main(){

}