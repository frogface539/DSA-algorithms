#include <iostream>
using namespace std;

class Heap{
    public:
    int *arr;
    int size;
    int index;

    Heap(int size){
        this->size = size;
        arr = new int[size];
        this->index = 0;
    }

    void print(){
        for(int i = 1; i <= index; i++){ // Loop from 1 to current index
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void insert(){

        // 1-based indexing
        if(index == size-1){ // Corrected comparison operator
            cout << "Overflow" << endl;
            return;
        }
        
        int val;
        cout << "Enter data: ";
        cin >> val;

        if(val == -1) {
            return;
        }

        index++;
        arr[index] = val;

        // Insert until the node reaches the root (index 1)
        int currentIndex = index;
        while(currentIndex > 1){
            int parentIndex = currentIndex / 2;

            if(arr[currentIndex] > arr[parentIndex]){
                swap(arr[currentIndex], arr[parentIndex]);
                currentIndex = parentIndex;
            }
            else{
                return;
            }
        }
    }

    void deleteNode(){
        if(index == 0){
            cout << "Underflow" << endl;
            return;
        }
        arr[1] = arr[index];
        index--;
        heapify(arr , index , 1);
    }
    
    void heapify(int *arr , int size , int index){
        int currentIndex = index;
        int leftIndex = 2 * index;
        int rightIndex = (2 * index) + 1;

        int largestIndex = index;

        if(leftIndex < size && arr[largestIndex] < arr[leftIndex]){
            swap(arr[leftIndex] , arr[largestIndex]);
            largestIndex = leftIndex;
        }

        if(rightIndex < size && arr[largestIndex] < arr[rightIndex]){
            swap(arr[rightIndex] , arr[largestIndex]);
            largestIndex = rightIndex;
        }

        if(largestIndex != index){
            index = largestIndex;
            heapify(arr , size , index);
        }

    }
};

int main(){
    Heap h(10);
    for(int i = 0; i < 5; i++) {
        h.insert();  // Loop to insert multiple values
    }
    h.print();
    return 0;
}
