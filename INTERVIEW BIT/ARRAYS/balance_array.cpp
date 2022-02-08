#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> arr){
    int n = arr.size();
    int oddsum = 0;
    int evensum = 0;
    for (int i = 0; i < n; i++)
    {
        if (i%2 == 0)
        {
            evensum += arr[i];
        }
        else
        {
            oddsum += arr[i];
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (i%2 == 0)
        {
            evensum -= arr[i];
            if (evensum == oddsum)
            {
                count++;
            }
            oddsum += arr[i];
        }
        else
        {
            oddsum -= arr[i];
            if (oddsum == evensum)
            {
                count++;
            }
            evensum += arr[i];
        }
    }
    return count;
}

int main(){
    
}