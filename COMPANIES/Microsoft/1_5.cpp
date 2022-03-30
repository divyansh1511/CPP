#include<bits/stdc++.h>
using namespace std;

static bool cmp(int a , int b){
    string a1 = to_string(a);
    string a2 = to_string(b);
    return a1 > a2;
}

string largest_number(int arr[] , int n){
    sort(arr , arr+n , cmp);
    int c = 0;
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            c++;
        }
        ans += arr[i];
    }
    if (n == c)
    {
        return "0";
    }
    return ans;
}

int main(){

}