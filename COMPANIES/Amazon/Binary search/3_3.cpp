#include<bits/stdc++.h>
using namespace std;

int rotatedsearcharr(vector<int> v , int B){
    int n = v.size();
    int i = 0 , j = n-1;
    while (i<=j)
    {
        int mid = i+(j-i)/2;
        if (v[mid] == B)
        {
            return mid;
        }
        else if (v[0] <= v[mid])
        {
            if (v[0] <= B && B < v[mid])
            {
                j = mid-1;
            }
            else
            {
                i = mid+1;
            }
        }
        else
        {
            if (v[mid] <= B && B < v[n-1])
            {
                i = mid+1;
            }
            else
            {
                j = mid-1;
            }
        }
    }
    return -1;
}

int main(){

}