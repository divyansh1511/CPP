#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string , int> myMap;

    myMap["A"] = 90;
    myMap["B"] = 80;
    myMap["C"] = 70;

    cout<<myMap["A"]<<endl;
    cout<<myMap.at("A")<<endl;

    cout<<myMap["D"]<<endl;
    cout<<myMap.size()<<endl;

    cout<<myMap.count("A")<<endl;   // it will give 0 or 1 
    myMap.erase("A");
    cout<<myMap.size()<<endl;
}