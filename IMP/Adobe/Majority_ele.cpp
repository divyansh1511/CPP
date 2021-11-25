#include<bits/stdc++.h>
using namespace std;

int majorityele(vector<int> arr){
    unordered_map<int,int>mp;
    for(int num : arr){
        if(++mp[num] > arr.size()/2){
            return num;
        }
    }
    return 0;
}

int majority(vector<int> arr){
    int major = arr[0];
    int count = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (count == 0)
        {
            count++;
            major = arr[i];
        }
        else if (major == arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return major;
}

int main(){
    vector<int> arr = {2,2,1,1,1,2,2};
    cout<<majorityele(arr)<<endl;
    cout<<majority(arr)<<endl;
}