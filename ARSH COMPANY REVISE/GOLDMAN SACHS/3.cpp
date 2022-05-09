#include<bits/stdc++.h>
using namespace std;

int countsubarr(int arr[] , int n , int k){
    int count = 0;
    int pro = 1;
    for (int start = 0 , end = 0; end < n; end++)
    {
        pro *= arr[end];
        while (start < end && pro >= k)
        {
            pro /= arr[start++];
        }
        if (pro < k)
        {
            int len = end - start + 1;
            count += len;
        }
    }
    return count;
}

int main(){
    int arr[] = {1,2,3,4};
    cout<<countsubarr(arr , 4 , 10)<<endl;
}