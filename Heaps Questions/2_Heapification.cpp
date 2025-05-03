#include <iostream>
using namespace std;

class Heap{
    int *arr;
    int capacity;
    int size;

    Heap(){
        this -> arr = new int[capacity];
        this -> capacity = capacity;
        this -> size = 0;
    }

    void insert(int val){
        if(size == capacity){
            cout << "overflow";
            return;
        }

        size++;
        arr[size] = val;
        int index = size;
        while( index > 1){
            int parentIndex = index/2;
            if(arr[parentIndex] < arr[index]){
                swap(arr[parentIndex] , arr[index]);
                parentIndex = index;
            }
            else{
                break;
            }
        }     
    }

    void heapify(int *arr , int size , int index){     //recursive solution used for insertion and deletion
        int leftIndex = 2 * index;
        int rightIndex = (2 * index) + 1;
        int largestIndex = index;

        if(largestIndex <= size && arr[largestIndex] < arr[leftIndex]){
            largestIndex = leftIndex;
        }

        if(largestIndex <= size && arr[largestIndex] < arr[rightIndex]){
            largestIndex = rightIndex;
        }

        if(index != largestIndex){
            swap(arr[index] , arr[largestIndex]);
            index = largestIndex;
            heapify(arr , size , index);
        }
    }

    void buildheap(int *arr , int size){    //using heapify
        for(int index = size/2 ; index<0 ; index--){
            heapify(arr , size , index);
        }
    }

    void HeapSort(){
        while(size != 1 ) {
            swap(arr[1], arr[size]);
            size--;
            heapify(arr,size,1);
        }
    }
};