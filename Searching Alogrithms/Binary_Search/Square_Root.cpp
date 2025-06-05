#include <vector>
#include <iostream>
using namespace std;

int Sqrt(int num){

    // In this question we will define a search space by ourselves ( 0 -> num )
    int s = 0;
    int e = num;
    int mid = s+(e-s)/2;
    int ans = -1;

    while(s <= e){
        mid = s+(e-s)/2;
        if(mid * mid < num){
            ans = mid;
            s = mid + 1;
        }

        else if(mid * mid == num){
            return mid;
        }

        else{
            e = mid - 1;
        }
    }
    return ans;
}

int main(){
    int sq = Sqrt(5);
    cout << sq;
}