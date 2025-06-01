#include <iostream>
#include <vector>
using namespace std;

void LinearSearch(vector<int>& arr , int element){
    bool found = 0;
    int n = arr.size();
    
    for(int i=0 ; i < n ; i++){
        if(arr[i] == element){
            cout << "Element found at: " << i<<endl;
            found = 1;
            break;
        }
    }

    if(found == 0){
            cout << "Element not found"<<endl;
    }
}

int main(){
    vector<int>data = {1,2,3,4,5,6,7};
    LinearSearch(data,5);
}