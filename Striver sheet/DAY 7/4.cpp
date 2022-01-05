#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &v){
    int count = 0;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] == v[i-1])
        {
            count++;
        }
        else
        {
            v[i-count] = v[i];
        }
    }
    return count;
}

int main(){

}