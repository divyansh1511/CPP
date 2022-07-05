#include<bits/stdc++.h>
using namespace std;

int raneBitwise(int left , int right){
    int trans = 0;
    while (left != right)
    {
        trans++;
        left >>= 1;
        right >>= 1;
    }
    return left << trans;
}

int main(){

}