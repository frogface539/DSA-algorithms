#include <vector>
#include <iostream>
using namespace std;

// [70,60,50,40,10,20,30]
// 40 is a pivot element with O(log n) complexity

int Pivot_Element(vector<int>& arr){
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e-s)/2;

    while(s <= e){
        mid = s + (e-s)/2;
        if(s==e){
            return s;
        }

        else if(mid < e && arr[mid] > arr[mid + 1]){
            return mid;
        }

        else if(mid > s && arr[mid] < arr[mid - 1]){
            return mid - 1;
        }

        else if(arr[s] > arr[mid]){
            e = mid - 1;
        }

        else{
            s = mid + 1;
        }
    }
    return -1;
}

int main(){
    vector<int>arr = {70,60,50,40,30,10,20};
    int pivotElement = Pivot_Element(arr);
    cout << "Pivot Element: "<<pivotElement;
}