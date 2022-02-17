#include<bits/stdc++.h>
using namespace std;

//-------------------------------------brute force----------------------------------//

void merge2sortedlist(vector<int> &arr1 , vector<int> &arr2){
    int n = arr2.size();
    for (int i = 0; i < n; i++)
    {
        arr1.push_back(arr2[i]);
    }
    sort(arr1.begin() , arr1.end());
}

//------------------------------------optimize------------------------------//

void merge2sortedlistopti(vector<int> &arr1 , vector<int> &arr2){
    int i = arr1.size() - 1;
    int j = arr2.size() - 1;
    
    int n = arr1.size() + arr2.size() - 1;
    arr1.resize(n+1);
    while (i >= 0 && j >= 0)
    {
        if (arr1[i] > arr2[j])
        {
            arr1[n--] = arr1[i--];
        }
        else
        {
            arr1[n--] = arr2[j--];
        }
    }
}

int main(){
    vector<int> arr1 = {1,5,8};
    vector<int> arr2 = {6,9};
    merge2sortedlistopti(arr1 , arr2);
    for (int i = 0; i < arr1.size(); i++)
    {
        cout<<arr1[i]<<" ";
    }
    
}