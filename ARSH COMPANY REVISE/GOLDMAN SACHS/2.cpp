#include<bits/stdc++.h>
using namespace std;

int overlapping(pair<int , int> l1 , pair<int , int> r1 , pair<int , int> l2 , pair<int , int> r2){
    if ((l2.first > l1.first && l2.first < r1.first) || (l2.second > l1.second && l2.second < r1.second))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(){

}