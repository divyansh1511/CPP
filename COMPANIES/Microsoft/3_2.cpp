#include<bits/stdc++.h>
using namespace std;

int firstrange(vector<int> a , int b){
    int n = a.size();
    int i = 0 , j = n-1;
    int ans = -1;
    while (i < j)
    {
        int mid = (i+j)/2;
        if (a[mid] == b)
        {
            ans = mid;
            j = mid-1;
        }
        else if (a[mid] < b)
        {
            i = mid+1;
        }
        else
        {
            j = mid-1;
        }
    }
    return ans;
}

int secondrange(vector<int> a , int b){
    int n = a.size();
    int i = 0 , j = n-1;
    int ans = -1;
    while (i < j)
    {
        int mid = (i+j)/2;
        if (a[mid] == b)
        {
            ans = mid;
            i = mid+1;
        }
        else if (a[mid] < b)
        {
            i = mid+1;
        }
        else
        {
            j = mid-1;
        }
    }
    return ans;
}

vector<int> searchrange(vector<int> A , int B){
    vector<int> v;
    int a = firstrange(A , B);
    if(a == -1){
        v.push_back(-1);
        v.push_back(-1);
        return v;
    }
    v.push_back(a);
    int b = secondrange(A , B);
    v.push_back(b);
    return v;
}

int main(){

}