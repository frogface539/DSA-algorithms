// This merge sort algorithm has space complexity of O(1) and is much shorter than the merge sort algorithm.

#include <bits/stdc++.h>
using namespace std;

    void inPlaceMerge(vector<int>&nums , int start , int mid , int end){
        int totalLength = end - start + 1;
        int gap = totalLength / 2 + totalLength % 2; //ceil

        while(gap > 0){

            int i = start;
            int j = start + gap;
            while(j<=end){
                if(nums[i] > nums[j]){
                    swap(nums[i] , nums[j]);
                }
                i++;
                j++;
            }

            if(gap == 1){
                gap = 0;
            }
            else{
                gap = gap/2 + gap%2;
            }
        }

    }


    void mergeSort(vector<int>&nums , vector<int>&temp , int start , int end){
        if(start >=end){
            return;
        }
        int mid = (start + end)/2;
        mergeSort(nums , temp , start , mid);
        mergeSort(nums , temp , mid + 1 , end);
        merge(nums , temp , start , mid , end);
    }


    vector<int> sortArray(vector<int>& nums) {
        vector<int>temp(nums.size() , 0);
        mergeSort(nums , temp , 0 , nums.size()-1);
        return nums;
    }


