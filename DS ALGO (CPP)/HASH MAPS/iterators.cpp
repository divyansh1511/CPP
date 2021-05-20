#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

void iteratoringhashmaps(){
    unordered_map<string , int> ourmap;
    ourmap["A"] = 10;
    ourmap["B"] = 20;
    ourmap["C"] = 30;
    ourmap["D"] = 40;

    unordered_map<string , int>::iterator it = ourmap.begin();
    while (it != ourmap.end())
    {
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
}

void iteratingvector(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    vector<int>::iterator it = v.begin();
    while (it != v.end())
    {
        cout<<*it<<endl;
        it++;
    }
    
}

int main(){
    iteratoringhashmaps();
    iteratingvector();
}