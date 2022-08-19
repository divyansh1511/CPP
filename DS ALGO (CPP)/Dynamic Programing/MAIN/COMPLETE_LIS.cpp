#include<bits/stdc++.h>
using namespace std;

//----------------------------LONGEST INCREASING SUBSEQUENCE-----------------------------//

int list1(int arr[] , int n){
    int lis[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && lis[i] < lis[j]+1)
            {
                lis[i] = lis[j]+1;
            }   
        }
    }
    return *max_element(lis , lis+n);
}

//----to print LIS----//

vector<int> list11(vector<int> arr){
    int n = arr.size();
    vector<int> dp(n , 1) , hash(n);
    int maxi = 0;
    int lastelementindex = -1;
    for (int i = 1; i < n; i++)
    {
        hash[i] = i;
        for (int j = 0; j < i; j++)
        {
            if(arr[i] > arr[j] && dp[i] < dp[j]+1){
                dp[i] = dp[j]+1;
                hash[i] = j;
            }
        }
        if(dp[i] > maxi){
            maxi = dp[i];
            lastelementindex = i;
        }
    }
    vector<int> ans;
    ans.push_back(arr[lastelementindex]);
    while (hash[lastelementindex] != lastelementindex)
    {
        lastelementindex = hash[lastelementindex];
        ans.push_back(arr[lastelementindex]);
    }
    reverse(ans.begin() , ans.end());
    return ans;
}

//-------------------------MAXIMUM SUM OF INCREASING SUBSEQUENCE------------------------//

int list2(int arr[] , int n){
    int lis[n];

    for (int i = 0; i < n; i++)
    {
        lis[i] = arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        // lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && lis[i] < lis[j]+arr[i])
            {
                lis[i] = lis[j]+arr[i];
            }   
        }
    }
    return *max_element(lis , lis+n);
}

//-------------------MAXIMUM PRODUCT OF INCREASING SUBSEQUENCE-------------------------------//

int list3(int arr[] , int n){
    int lis[n];

    for (int i = 0; i < n; i++)
    {
        lis[i] = arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && lis[i] < lis[j]*arr[i])
            {
                lis[i] = lis[j]*arr[i];
            }   
        }
    }
    return *max_element(lis , lis+n);
}

//-------------------------MAX CHAIN LENGTH------------------------------------//

int maxchainlength(vector<pair<int , int>> v, int n){
    vector<int> mcl(n);

    for (int i = 0; i < n; i++ ) {
        mcl[i] = 1; 
    }

    for (int i = 1; i < n; i++ ){
        for (int j = 0; j < i; j++){ 
            if ( v[i].first > v[j].second && mcl[i] < mcl[j] + 1){ 
                mcl[i] = mcl[j] + 1; 
            }
        }
    }

    return *max_element(mcl.begin() , mcl.end());
}

int main(){
    int arr[] = {3, 100, 4, 5, 150, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<list3(arr , n)<<endl;
}