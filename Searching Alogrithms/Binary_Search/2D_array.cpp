#include <iostream>
#include <vector>
using namespace std;

bool BinarySearch(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int totalElements = rows*cols;
    int s = 0;
    int e = totalElements - 1;
    int mid = s + (e-s)/2;

    while(s <= e){
        int rowIndex = mid/cols;
         int colIndex = mid%cols;
        if(matrix[rowIndex][colIndex] == target){
            return true;
        }
        if(matrix[rowIndex][colIndex] < target){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return false;
}

bool LinearSearch(vector<vector<int>>& matrix, int target){
    for(int i=0 ; i<matrix.size() ; i++){
        for(int j=0 ; j< matrix[0].size() ; j++){
            if(matrix[i][j] == target){
                return true;
            }
        }
    }
    return false;
}

int main(){
    vector<vector<int>> data = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 5;
    bool linear = LinearSearch(data,target);
    bool binary = BinarySearch(data,target);
    cout << linear << endl;
    cout << binary << endl;
}