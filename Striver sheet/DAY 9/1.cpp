#include<bits/stdc++.h>
using namespace std;

void helper(int i , int arr[] , int n , vector<int> &ans , int sum){
    if (i == n)
    {
        ans.push_back(sum);
        return;
    }
    helper(i+1 , arr , n , ans , sum + arr[i]);
    helper(i+1 , arr , n , ans , sum);
}

vector<int> subsetsum(int arr[] , int n){
    vector<int> ans;
    helper(0 , arr , n , ans , 0);
    return ans;
}

int main(){

}