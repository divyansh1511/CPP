#include<bits/stdc++.h>
using namespace std;

int countelementslessthanmid(vector<int> &v, int x)
{
    int low=0;
    int high=v.size()-1;
    int mid;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(v[mid]<=x) // Checking for next highest element
            low=mid+1;
        else
            high=mid-1;
    }
    return low;
}

int findMedian(vector<vector<int> > &A)
{
    int n=A.size();
    int m=A[0].size();
    int low=1;
    int high=pow(10,9);
    int mid;

    while(low<=high)
    {
        mid=low+(high-low)/2;
        int count=0;
        for(int i=0;i<n;i++)
            count+=countelementslessthanmid(A[i],mid);
        if(count<=(n*m/2))
            low=mid+1;
        else
            high=mid-1;
    }
    return low;        
}



int main(){

}