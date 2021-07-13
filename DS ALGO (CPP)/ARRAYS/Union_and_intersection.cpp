#include<iostream>
#include<set>
using namespace std;

void unionof(int arr1[] , int arr2[] , int n , int m){
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        s.insert(arr2[i]);
    }
    
    for (auto it = s.begin(); it != s.end() ; it++)
    {
        cout<<*it<<endl;
    }
}

void intersection(int arr1[] , int arr2[] , int n , int m){
    int i = 0 , j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr2[j] < arr1[i])
        {
            j++;
        }
        else
        {
            cout<<arr1[i]<<endl;
            i++;
            j++;
        }
        
    }
    
}

int main(){
    int arr1[] = {1,3,5,7,9};
    int arr2[] = {2,3,6,8,10};
    unionof(arr1 , arr2 ,5 ,5);
    intersection(arr1 ,arr2 , 5 ,5);
}