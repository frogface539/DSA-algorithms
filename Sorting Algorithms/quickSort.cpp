#include <bits/stdc++.h>
using namespace std;

void quickSort(vector<int>&nums , int start , int end){

    int i = start - 1;
    int j = start;
    int pivot = end;

    if(start >= end){
        return;
    }
    
    while(j<pivot){
        if(nums[j] < nums[pivot]){
            i++;
            swap(nums[i] , nums[j]);
        }
        j++;
    }
    i++;
    swap(nums[i] , nums[pivot]);
    quickSort(nums , start , i - 1);
    quickSort(nums , i + 1 , end);

}