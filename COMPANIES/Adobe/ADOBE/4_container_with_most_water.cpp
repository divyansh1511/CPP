#include<bits/stdc++.h>
using namespace std;

int maxcontainer(vector<int> v){
    int left = 0;
    int right = v.size() - 1;
    int ans = 0;
    while (left < right)
    {
        ans = max(ans , (right-left)*min(v[left] , v[right]));
        v[left] > v[right] ? right-- : left++;
    }
    return ans;
}

int main(){

}