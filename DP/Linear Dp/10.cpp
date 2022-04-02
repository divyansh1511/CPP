#include<bits/stdc++.h>
using namespace std;

int permutation(int n , int i){
    if (i == 0)
    {
        return 1;
    }
    return n*permutation(n-1 , i-1);
}

int count_numbers(int n){
    int sum = 1;
    if (n > 0)
    {
        int end = n > 10 ? 10 : n;
        for (int i = 0; i < end; i++)
        {
            sum += 9*permutation(9 , i);
        }
    }
    return sum;
}

int main(){

}