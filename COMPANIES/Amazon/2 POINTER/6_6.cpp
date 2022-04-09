#include<bits/stdc++.h>
using namespace std;

int pairwithgivendiff(vector<int> v , int diff){
    int i = 0 , j =  1;
    int n = v.size();
    while (i < n && j < n)
    {
        if (v[j] - v[i] == diff && i != j)
        {
            return 1;
        }
        else if (v[j] - v[i] > diff)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return 0;
}

int main(){

}