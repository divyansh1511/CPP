#include<bits/stdc++.h>
using namespace std;

int minsteps(vector<int> &A , vector<int> &B){
    int n = A.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (abs(A[i] - A[i+1]) <= abs(B[i] - B[i+1]))
        {
            ans += (abs(B[i] - B[i+1]));
        }
        else
        {
            ans += (abs(A[i] - A[i+1]));
        }
    }
    return ans;
}

int main(){

}