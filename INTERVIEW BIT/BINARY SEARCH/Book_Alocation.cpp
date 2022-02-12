#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr , int m , int mid){
    int studentcount = 1;
    int currsum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        currsum += arr[i];
        if (currsum > mid)
        {
            studentcount++;
            currsum = arr[i];
        }
        if (studentcount > m)
        {
            return false;
        }
    }
    return true;
}

int books(vector<int> &arr , int B){
    int n = arr.size();
    long long int sum = 0;
    int maxele = arr[0];
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxele = max(maxele , arr[i]);
    }
    long long int s = maxele;
    long long int e = sum;
    int mid = s + (e-s)/2;
    while (s <= e)
    {
        if (isPossible(arr , B , mid))
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int main(){
    vector<int> v = {10 , 20 , 30 , 40};
    cout<<books(v , 2)<<endl;
}