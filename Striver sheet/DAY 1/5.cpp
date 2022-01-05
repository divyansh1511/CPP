//-----------------SORT 0 , 1 , 2-----------//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void sortcolors(vector<int> &v){
    int n = v.size();
    int countz = 0 , countone = 0 , counttwo = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            countz++;
        }
        else if (v[i] == 1)
        {
            countone++;
        }
        else
        {
            counttwo++;
        }
    }
    for (int i = 0; i < countz; i++)
    {
        v[i] = 0;
    }
    for(int i = countz; i<countz+countone;i++){
        v[i] = 1;
    }
    for (int i = countone+countz; i < countone+countz+counttwo; i++)
    {
        v[i] = 2;
    }
}

//-------------------DUTCH FLAG METHOD-----------------------//

void sortcolors1(vector<int> &v){
    int low = 0;
    int mid = 0;
    int high = v.size() - 1;
    while (mid <= high)
    {
        if (v[mid] == 0)
        {
            swap(v[low] , v[mid]);
            low++;
            mid++;
        }
        else if (v[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(v[mid] , v[high]);
            high--;
        }
    }
}

int main(){
    vector<int> v =  {1,0,2,0,1,1,2,1};
    sortcolors1(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    
}