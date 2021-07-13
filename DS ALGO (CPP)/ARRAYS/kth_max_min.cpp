#include<iostream>
#include<set>
using namespace std;

void solve(int arr[] , int n , int k){
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }
    set<int>:: iterator itr1 = s.begin();
    advance(itr1 , k-1);
    cout<<"min :"<<*itr1<<endl;

    set<int>:: iterator itr2 = s.begin();
    advance(itr2 , n-k);
    cout<<"max :"<<*itr2<<endl;
}

int main(){
    int arr[] = {5,7,9,3,4};
    solve(arr , 5 , 1);
}