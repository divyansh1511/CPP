#include<bits/stdc++.h>
using namespace std;

int majorityele(vector<int> arr , int n){
    int counter = 0 , majority = 0;
    for(auto it : arr){
        if (!counter)
        {
            majority = it;
        }
        counter += majority == it ? 1 : -1;
    }
    return majority;
}

int main(){

}