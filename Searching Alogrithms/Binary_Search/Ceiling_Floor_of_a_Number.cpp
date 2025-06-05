#include <iostream>
#include <vector>
using namespace std;

int Ceiling(vector<int>& arr, int target){
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s <= e){
        if(arr[mid] < target){
            s = mid + 1;
        }

        else{
            ans = arr[mid];
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int Floor(vector<int>& arr, int target){
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s <= e){
        if(arr[mid] > target){
            e = mid - 1;
        }

        else{
            ans = arr[mid];
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main(){
    vector<int> data = {10,20,30,40,50,60,70,80,90,100};
    int target = 23;
    int ceil = Ceiling(data,target);
    int floor = Floor(data,target);
    cout << "ceil of " << target << " is: " << ceil<<endl;
    cout << "floor of " << target << " is: " << floor<<endl;
}