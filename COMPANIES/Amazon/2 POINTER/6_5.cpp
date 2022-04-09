#include<bits/stdc++.h>
using namespace std;

int removeele(vector<int> arr , int n , int b){
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != b)
        {
            arr[c] = arr[i];
            c++;
        }
    }
    return c;
}

int main(){

}