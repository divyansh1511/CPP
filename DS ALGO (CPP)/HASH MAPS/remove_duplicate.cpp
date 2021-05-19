#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> removeduplicate(int* arr , int size){
    vector<int> output;
    unordered_map<int , bool> visited;
    for (int i = 0; i < size; i++)
    {
        if (visited.count(arr[i]) > 0)
        {
            continue;
        }
        visited[arr[i]] = true;
        output.push_back(arr[i]);
    }
    return output;
}

int main(){
    int arr[] = {1,1,2,2,4,7,5,7,7,6};
    vector<int> output = removeduplicate(arr , 10);
    for (int i = 0; i < output.size(); i++)
    {
        cout<<output[i]<<endl;
    }
    
}