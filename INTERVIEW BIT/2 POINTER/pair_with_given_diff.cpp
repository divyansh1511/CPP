#include<bits/stdc++.h>
using namespace std;

int pairdiff(vector<int> arr , int k){
    sort(arr.begin() , arr.end());
    int n = arr.size();
    int i=0,j=1;
    while (i<n && j<n)
    {
        if ((arr[j] - arr[i]) == k && i != j)
        {
            return 1;
        }
        else if ((arr[j] - arr[i]) > k)
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return 0;
}

int main(){

}