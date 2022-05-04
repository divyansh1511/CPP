#include<bits/stdc++.h>
using namespace std;

string excelcolumnNumber(int n){
    string ans = "";
    while (n)
    {
        ans += char((n-1)%26 + 'A');
        n = (n-1)/26;
    }
    reverse(ans.begin() , ans.end());
    return ans;
}

int main(){

}