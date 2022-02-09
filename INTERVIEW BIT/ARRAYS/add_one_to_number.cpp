#include<bits/stdc++.h>
using namespace std;

vector<int> addone(vector<int> arr){
    reverse(arr.begin() , arr.end());
    vector<int> v;
    int n = arr.size();
    int carry = 1;
    for (int i = 0; i < n; i++)
    {
        int sum = arr[i] + carry;
        v.push_back(sum%10);
        sum = sum/10;
    }
    while (carry != 0)
    {
        v.push_back(carry%10);
        carry = carry/10;
    }
    while (v[v.size() - 1] == 0 && v.size() > 1)
    {
        v.pop_back();
    }
    reverse(v.begin() , v.end());
    return v;
}

vector<int> addoneopti(vector<int> arr){
    if (arr.size() == 1 && arr[0] < 9)
    {
        arr[0] = arr[0]+1;
        return arr;
    }
    int k = 0;
    while (arr[k] == 0)
    {
        if (arr[k] != 0)
        {
            break;
        }
        auto it = arr.begin()+k;
        arr.erase(it);
    }
    int n = arr.size();
    reverse(arr.begin() , arr.end());
    int a = arr[0]+1;
    if (a < 10)
    {
        arr[0] = a;
        reverse(arr.begin() , arr.end());
        return arr;
    }
    else
    {
        int carry = a/10;
        arr[0] = a%10;
        int i = 1;
        while (carry != 0 && i < n)
        {
            int b = arr[i]+carry;
            arr[i] = b%10;
            carry = b/10;
            i++;
        }
        if(carry != 0){
            arr.push_back(carry);
        }
        reverse(arr.begin() , arr.end());
        return arr;
    }
}

int main(){

}