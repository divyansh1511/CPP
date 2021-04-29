#include<iostream>
using namespace std;

void zigzag(int input[][10] , int rows , int cols){
    for (int col = 0; col < cols; col++)
    {
        if (col%2 == 0)
        {
            for (int row = 0; row < rows; row++)
            {
                cout<<input[row][col]<<" ";
            }
        }
        else
        {
            for (int row = rows-1; row >= 0; row--)
            {
                cout<<input[row][col]<<" ";
            }
        }
        cout<<endl;
    }    
}

int main(){
    int arr[5][10] = {{1,2,3},{4,5,6},{7,8,9}};
    zigzag(arr , 3 ,3);
}