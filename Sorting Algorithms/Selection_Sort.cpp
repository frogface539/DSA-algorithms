#include <stdio.h>
using namespace std;
#include <vector>

void selection_sort(vector<int>& arr){
    for(int i=0 ; i<arr.size()-1 ; i++){
        int mini = 0;
        for(int j = 0 ; j<arr.size() ; j++){
            if(arr[i] < arr[mini]){
                j = mini;
            }
            swap(arr[i],arr[mini]);
        }
    }
}

int main(){
    vector<int>arr({1,4,6,2,1,0,2,3,7});
    selection_sort(arr);
    return 0;
}