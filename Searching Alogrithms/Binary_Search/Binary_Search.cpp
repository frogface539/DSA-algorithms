#include <iostream>
#include <vector>
using namespace std;

void BinarySearch(vector<int>& arr , int element){
    int start = 0;
    int end = arr.size() - 1;
    int mid = (start + end) /2;

    while(start <= end){
        mid = (start + end) /2;
        if(arr[mid] == element){
            cout << "Element Found at: " << arr[mid]<<endl;
            return;
        }

        else if(arr[mid] > element){
            end = mid - 1;
        }

        else if(arr[mid] < element){
            start = mid + 1;
        }
    }
    cout << "Element not found....";
}

int firstOccurence(vector<int>& arr , int target){

    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s<=e){
        mid = s + (e-s)/2;
        if(arr[mid] == target){
            ans = mid;
            e = mid - 1;
        }

        else if(arr[mid] > target){
            e = mid - 1;
        }

        else if(arr[mid] < target){
            s = mid + 1;
        }
    }
    return ans;
}

int lastOccuerence(vector<int>& arr , int target){

    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s<=e){

        mid = s + (e-s)/2;

        if(arr[mid] == target){
            ans = mid;
            s = mid + 1;
        }

        else if(arr[mid] > target){
            e = mid - 1;
        }

        else if(arr[mid] < target){
            s = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int>data = {1,2,2,2,2,2,3,4,5,6,7};
    BinarySearch(data,2);
    int first = firstOccurence(data,2);
    int last = lastOccuerence(data,2);
    cout << "first Occurence: " << first<<endl;
    cout << "last Occurence: " << last<<endl;
    cout << "Total Occurence: " << (last - first) + 1<<endl;
}