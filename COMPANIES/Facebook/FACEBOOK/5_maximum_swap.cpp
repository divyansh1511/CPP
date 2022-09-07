#include<bits/stdc++.h>
using namespace std;

int maximum_swaps(int num){
    string s = to_string(num);

    int maxdigit = -1 , maxidx = -1;
    int leftidx = -1 , rightidx = -1;

    int n = s.length();

    for (int i = n-1; i >= 0; i--)
    {
        if (s[i] - '0' > maxdigit)
        {
            maxdigit = s[i]-'0';
            maxidx = i;
            continue;
        }
        
        if (s[i] - '0' < maxdigit)
        {
            leftidx = i;
            rightidx = maxidx;
        }
    }
    if (leftidx == -1)
    {
        return num;
    }
    swap(s[leftidx] , s[rightidx]);
    return stoi(s);
}

int main(){

}