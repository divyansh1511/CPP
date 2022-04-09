#include<bits/stdc++.h>
using namespace std;

int cointainermostwater(int arr[] , int n){
    int i = 0 , j = n-1;
    int ans = 0;
    while (i < j)
    {
        int mini = min(arr[i] , arr[j]);
        int area = mini*(j-i);
        ans = max(ans , area);
        if (mini == arr[i])
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return ans;
}

int main(){

}