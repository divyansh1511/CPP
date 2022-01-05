#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i=0;i<n;i++){
        if(matrix[i][0] == target){
            return true;
        }
        if(matrix[i][0] > target){
            if(i == 0){
                return false;
            }
            else{
                for(int j=0;j<m;j++){
                    if(matrix[i-1][j] == target){
                        return true;
                    }
                }
                break;
            }
        }
        else if(i == n-1){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == target){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout<<searchMatrix(matrix , 3)<<endl;
}