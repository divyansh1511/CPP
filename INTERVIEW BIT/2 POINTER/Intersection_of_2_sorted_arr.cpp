#include<bits/stdc++.h>
using namespace std;

vector<int> intersectedarr(vector<int> arr1 , vector<int> arr2){
    vector<int> ans;
    int i = 0 , j = 0;
    int n = arr1.size() , m = arr2.size();
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]);
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else{
            i++;
        }
    }
    return ans;
}

int main(){

}