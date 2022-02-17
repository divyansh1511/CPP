#include<bits/stdc++.h>
using namespace std;

//--------------------brute force --- 2 for loops--------------------------//

//--------------------------opti----------------//

int counting(vector<int> &arr , int k){
    int n = arr.size();
    int ans = 0;
    int i = 0 , j = 0;
    int sum = 0;
    while (i < n)
    {
        sum += arr[i];
        while (sum >= k)
        {
            sum -= arr[j];
            j++;
        }
        ans += (i-j+1);
        i++;
    }
    return ans;
}

int main(){

}