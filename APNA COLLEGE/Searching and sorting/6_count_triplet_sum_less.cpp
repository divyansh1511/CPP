#include<bits/stdc++.h>
using namespace std;

int counttriplet(int arr[] , int n , int sum){
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i+1 , k = n-1;
        while (j < k)
        {
            if (arr[i] + arr[j] + arr[k] >= sum)
            {
                k--;
            }
            else
            {
                count += (k-j);
                j++;
            }
        }
    }
    return count;
}

int main(){

}