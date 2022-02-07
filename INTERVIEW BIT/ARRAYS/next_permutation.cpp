#include<bits/stdc++.h>
using namespace std;

void nextpermutation(vector<int> arr){
    int n = arr.size();
    int l , k;
    for (k = n-2; k >= 0; k--)
    {
        if (arr[k] < arr[k+1])
        {
            break;
        }
    }
    if (k < 0)
    {
        reverse(arr.begin() , arr.end());
    }
    else
    {
        for (l = n-1; l > k; l--)
        {
            if (arr[l] > arr[k])
            {
                break;
            }
        }
        swap(arr[l] , arr[k]);
        reverse(arr.begin()+k+1 , arr.end());
    }
}

int main(){

}