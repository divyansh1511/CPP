#include<bits/stdc++.h>
using namespace std;

int findHindex2(vector<int> arr){
    int n = arr.size();
    int i = 0 , j = n-1;
    while (i <= j)
    {
        int mid = (i+j)/2;
        if (arr[mid] < n-mid)
        {
            i = mid+1;
        }
        else
        {
            j = mid-1;
        }
    }
    return n-i;
}

int main(){

}