#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void intersection(int* arr1 , int* arr2 , int size1 , int size2){
    unordered_map<int , int> map;
    for (int i = 0; i < size1; i++)
    {
        int a = arr1[i];
        if (map.count(a) == 0)
        {
            map[a] = 1;
        }
        else
        {
            int prevcount = map[a];
            map[a] = prevcount+1;
        }
    }
    
    for (int i = 0; i < size2; i++)
    {
        int a = arr2[i];
        if (map.count(a) > 0)
        {
            int count = map[a];
            if (count != 0)
            {
                map[a] = count-1;
                cout<<a<<endl;
            }
        }   
    }   
}

int main(){
    int arr1[] = {2,5,4,3,6,7,3,2};
    int arr2[] = {3,6,2,8,9,5,2};
    intersection(arr1 , arr2 , 8 , 7);   
}