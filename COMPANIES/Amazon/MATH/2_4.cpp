#include<bits/stdc++.h>
using namespace std;

int powerof2(int n){
    if (n == 1)
    {
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (n%i == 0)
        {
            for (int j = 2; j < 32; j++)
            {
                if (pow(i , j) > n)
                {
                    break;
                }
                if (pow(i , j) == n)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(){

}