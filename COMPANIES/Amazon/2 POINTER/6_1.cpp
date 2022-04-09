#include<bits/stdc++.h>
using namespace std;

void merge2sortedlist(vector<int> &A , vector<int> B){
    vector<int> C = A;
    A.clear();
    int i = 0 , j = 0;
    int n = C.size() , m = B.size();
    while (true)
    {
        if (i >= n || j >= m)
        {
            break;
        }
        if (C[i] < B[j])
        {
            A.push_back(C[i]);
            i++;
        }
        else if (C[i] > B[j])
        {
            A.push_back(B[j]);
            j++;
        }
        else
        {
            A.push_back(C[i]);
            A.push_back(B[j]);
            i++;
            j++;
        }
    }
    if (i < n)
    {
        while (i < n)
        {
            A.push_back(C[i]);
            i++;
        }
    }
    if (j < m)
    {
        while (j < m)
        {
            A.push_back(C[j]);
            j++;
        }
    }
}

int main(){

}