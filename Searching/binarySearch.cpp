// TC = O (log n)
#include <iostream>
#include <vector>
using namespace std;
// TC O(log n) and SC O(1)
int binarySearch(vector<int> arr, int target){
    int st = 0, end = arr.size()-1;

    while (st <= end)
    {
       int mid =  st + ( end - st ) / 2;

       if(target > arr[mid]){
        st = mid + 1;
       } else if(target < arr[mid]){
        end = mid - 1;
       } else 
        return mid;
    }
    return -1;
}
// O(log n) and SC O(log n)
int BS_byRecursion(vector<int> arr, int target, int st, int end){
    
    if(st <= end){
        int mid = st + ( end - st ) / 2;
        if(target > arr[mid])
            return BS_byRecursion(arr, target, mid+1, end);
        else if( target < arr[mid])
            return BS_byRecursion(arr, target, st,mid-1);
        else    
            return mid;
    }
    return -1;
}

int main(){
    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12};// odd
    int tar1 = 12;
    int st = 0, end1 = arr1.size()-1;

    cout << "For odd one: " << binarySearch(arr1, tar1) << endl;
    cout << "For odd one(Recursion): " << BS_byRecursion(arr1, tar1, st, end1 ) << endl;

    vector<int> arr2 = {-1, 0, 3, 5, 9, 12}; // even
    int tar2 = 0;
    int end2 = arr2.size()-1;

    cout << "For even one: " << binarySearch(arr2, tar2) << endl;
    cout << "For even one(Recursion): " << BS_byRecursion(arr2, tar2, st, end2) << endl;
    return 0;
}