#include<iostream>
#include<vector>
using namespace std;

int countGoodTriplets(vector<int> arr, int a, int b, int c) {
    int ct = 0;
    int n = arr.size();
    for(int i = 0; i<n-2; i++)
    {
        for(int j = i+1; j<n-1; j++)
        {
            if(abs(arr[i]-arr[j])<=a){
                for(int k = j+1; k<n; k++)
                {
                    if(abs(arr[j]-arr[k])<=b && abs(arr[i]-arr[k])<=c)
                        ct++;
                }
            }
        }
    }
    return ct;
}

int main(){
    vector<int> arr;
    int n,a,b,c;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cin>>a>>b>>c;
    cout<<countGoodTriplets(arr , a,b,c)<<endl;
}