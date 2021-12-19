#include<bits/stdc++.h>
using namespace std;

//--------------------------------------------KNAPSACK 0 1 -----------------------------------------//

int knapsackrec(int wt[] , int val[] , int W , int n){
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (wt[n-1] <= W)
    {
        return max(val[n-1] + knapsackrec(wt , val , W-wt[n-1] , n-1) , knapsackrec(wt , val , W , n-1));
    }
    else
    {
        return knapsackrec(wt , val , W , n-1);
    }
}

int knapsackmem(int wt[] , int val[] , int W , int n){
    static int dp[1002][1002];
    memset(dp , -1 , sizeof(dp));

    if (n == 0 || W == 0)
    {
        return 0;
    }

    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }
    
    if (wt[n-1] <= W)
    {
        return dp[n][W] = max(val[n-1] + knapsackmem(wt , val , W-wt[n-1] , n-1) , knapsackmem(wt , val , W , n-1));
    }
    else
    {
        return dp[n][W] = knapsackmem(wt , val , W , n-1);
    }
}

int knapsackdp(int wt[] , int val[] , int W , int n){
    int dp[n+1][W+1];
    memset(dp , 0 , sizeof(dp));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] == 0;
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i-1] <= j)
            {
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]] , dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

//-------------------------------------SUBSET SUM PROBLEM------------------------------------//

bool subsetrec(int wt[] , int sum , int n){
    if (n == 0 && sum == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return false;
    }
    if (sum == 0)
    {
        return true;
    }
    if (wt[n-1] <= sum)
    {
        return subsetrec(wt , sum - wt[n-1] , n-1) || subsetrec(wt , sum , n-1);
    }
    else
    {
        return subsetrec(wt , sum , n-1);
    }
}

bool subsetmem(int wt[] , int sum , int n){
    static int dp[1002][1002];
    memset(dp , -1 , sizeof(dp));
    if (sum == 0 && n == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return false;
    }
    if (sum == 0)
    {
        return true;
    }
    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }
    if (wt[n-1] <= sum)
    {
        return dp[n][sum] = dp[n-1][sum-wt[n-1]] || dp[n-1][sum];
    }
    else
    {
        return dp[n][sum] = dp[n-1][sum];
    }   
}

bool subsetdp(int wt[] , int sum , int n){
    int dp[n+1][sum+1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }
    for (int i = 0; i <= sum; i++)
    {
        dp[0][i] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (wt[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j- wt[i-1]] || dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

//------------------------------------EQUAL SUM PARTITION------------------------

int EqualSumPartition(int arr[] , int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum % 2 != 0)
    {
        return false;
    }
    return subsetdp(arr , sum/2 , n);
}

//----------------------------------COUNT SUBSET BY GIVEN SUM-------------------------

int countsubset(int arr[] , int n , int sum){
    if (n == 0 && sum == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    if (sum == 0)
    {
        return 1;
    }
    if (arr[n-1] <= sum)
    {
        return countsubset(arr , n-1 , sum-arr[n-1]) + countsubset(arr , n-1 , sum);
    }
    else
    {
        return countsubset(arr , n-1 , sum);
    }
}

int countsubsetdp(int arr[] , int n , int sum){
    int dp[n+1][sum+1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

//-----------------------------------------count subset of given diff----------------------

int countsubsetdiff(int arr[] , int n , int diff){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int sum1 = (sum + diff)/2;
    return countsubsetdp(arr , n , sum1);
}

//---------------------------------TARGET SUM ----------------------------------

int targetsum(int nums[] , int target , int n){
    target = abs(target);
    // int n = nums.size();
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += nums[i];
    } 
    int sum1 = (sum + target)/2;
    if(sum < target || (sum + target) % 2 != 0)
        return 0;
    return countsubsetdp(nums , n , sum1);
}

int main(){
    // int wt[] = {1,3,4,5};
    // int prices[] = {1,4,5,7};
    // cout<<knapsackrec(wt , prices , 7 , 4)<<endl;
    // cout<<knapsackmem(wt , prices , 7 , 4)<<endl;
    // cout<<knapsackdp(wt , prices , 7 , 4)<<endl;
    // int arr[] = {2,3,7,8,10};
    // cout<<subsetrec(arr , 11 , 5)<<endl;
    // cout<<subsetmem(arr , 11 , 5)<<endl;
    // cout<<subsetdp(arr , 11 , 5)<<endl;
    // int arr1[] = {1,5,11,5};
    // cout<<EqualSumPartition(arr1 , 4)<<endl;
    // int arr[] = {2,3,5,6,8,10};
    // cout<<countsubset(arr , 6 , 10)<<endl;
    // cout<<countsubsetdp(arr , 6 , 10)<<endl;
    int arr[] = {1,1,2,3};
    cout<<countsubsetdiff(arr , 4 , 1)<<endl;
}