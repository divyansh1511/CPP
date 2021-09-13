#include<iostream>
using namespace std;

void solve(string a, int l , int r){
    if (l == r)
    {
        cout<<a<<endl;
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(a[l] , a[i]);
            solve(a , l+1 , r);
            swap(a[l] , a[i]);
        }
    }
}

int main(){
    string a = "ABC";
    solve(a , 0 , a.length() - 1);
}