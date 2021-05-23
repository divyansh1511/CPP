#include<iostream>
using namespace std;

int editdistancedp(string s1 ,string s2){
    int m = s1.length();
    int n = s2.length();
    int arr[m+1][n+1];
    for (int i = 0; i < m+1; i++)
    {
        arr[i][0] = i;
    }
    for (int i = 0; i < n+1; i++)
    {
        arr[0][i] = i;
    }
    for (int i = 1; i < m+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if (s1[m-i] == s2[n-j])
            {
                arr[i][j] = arr[i-1][j-1];
            }
            else
            {
                arr[i][j] = 1+min(min(arr[i-1][j] , arr[i][j-1]) , arr[i-1][j-1]);
            }
        }
    }
    return arr[m][n];
}

int main(){
    cout<<editdistancedp("abcd","ecd")<<endl;
}