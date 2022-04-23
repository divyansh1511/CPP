#include<bits/stdc++.h>
using namespace std;

int heightchecker(int arr[] , int n){
    int count = 0;
    vector<int> v(101 , 0);
    for (int i = 0; i < n; i++)
    {
        v[arr[i]]++;
    }
    int i = 1 , j = 0;
    while (j < n)
    {
        if (v[i] != 0)
        {
            if (i != arr[j])
            {
                count++;
            }
            j++;
            v[i]--;
        }
        else
        {
            i++;
        }
    }
    return count;
}

int main(){

}