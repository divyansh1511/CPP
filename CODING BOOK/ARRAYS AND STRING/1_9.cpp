#include<bits/stdc++.h>
using namespace std;

bool isRotation(string s1 , string s2){
    return (s1.size() == s2.size()) && (s1+s1).find(s2) != string::npos;
}

int main(){
    
}