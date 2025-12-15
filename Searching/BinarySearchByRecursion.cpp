#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int BS(vector<int> arr, int tar, int st, int end) {// TC :O(log n), SC: O(log n)
    if( st <= end ) {
        int mid = st + (end - st) / 2;
        
        if(arr[mid] == tar) return mid;
        else if(arr[mid] <= tar) {
            return BS(arr, tar, mid+1, end);
        } else {
            return BS(arr, tar, st, mid-1);
        }
    }
    return -1;
}

int main(){
    int n;
    vector<int> arr = {1, 4, 3, 2};
    sort(arr.begin(), arr.end());

    cout << "Binary Search: " <<  BS(arr, 4, 0, arr.size()) << endl;
    return 0;
}