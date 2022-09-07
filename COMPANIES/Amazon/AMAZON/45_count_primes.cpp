#include<bits/stdc++.h>
using namespace std;

int countprimes(int n){
    vector<bool> v(n , true);
    for (int i = 0; i < sqrt(n); i++)
    {
        if (v[i] == false)
        {
            for (int j = i*i; j < n; j += i)
            {
                v[j] = false;
            }
        }
    }
    return count(v.begin() , v.end() , true);
}

int main(){

}