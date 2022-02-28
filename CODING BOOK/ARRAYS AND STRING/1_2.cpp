#include<bits/stdc++.h>
using namespace std;

//--------------------sort elements-------------------------//

bool checkPermuatation(string s1 , string s2){
    sort(s1.begin() , s1.end());
    sort(s2.begin() , s2.end());
    if (s1 == s2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//-----------------------arr of size n------------------------//

bool checkpermutation(string s1 , string s2){
    if (s1.length() != s2.length())
    {
        return false;
    }
    int n = s1.length();
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[s1[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if(arr[s2[i]] == 0){
            return false;
        }
        arr[s2[i]]--;
    }
    return true;
}

int main(){

}