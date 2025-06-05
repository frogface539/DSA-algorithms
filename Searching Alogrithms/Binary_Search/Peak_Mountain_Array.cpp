#include <vector>
#include <iostream>
using namespace std;

int PeakMountainArray(vector<int>& arr){
    int s = 0;
    int e = arr.size() - 1;
    int mid = s+(e-s)/2;

    while(s < e){
        mid = s+(e-s)/2;
        if(arr[mid] < arr[mid+1]){
            s = mid + 1;
        }
        else{
            e = mid;
        }
    }
    return arr[e];
}

int main(){
    vector<int> data = {0,2,1,0};
    int peak = PeakMountainArray(data);
    cout << "Peak Element: "<<peak;
}