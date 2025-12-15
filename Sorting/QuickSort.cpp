// Quick sort
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int st, int end) {
    int idx = st-1, pivot = arr[end];

    for(int j=st; j<end; j++) {
        if(arr[j] <= pivot) { // change < to > for decreasing
            idx++;
            swap(arr[j], arr[idx]);
        }
    }

    idx++;
    swap(arr[end], arr[idx]);
    return idx;
}

void quickSort(vector<int> &arr, int st, int end) { // O(n log n) & for worst case TC = O ( n^2) when pivor is either smallest or largest while constant SC.
    if(st < end) {
        int pivIdx = partition(arr, st, end);

        quickSort(arr, st, pivIdx-1); // left half
        quickSort(arr, pivIdx+1, end); // right half
    }
}

int main() {
    vector<int> arr = {12, 31, 35, 8, 32, 17};
    quickSort(arr, 0, arr.size()-1);

    cout << "Array = ";
    for(int val : arr) {
        cout << val << ", ";
    }
    cout << endl;

    return 0;
}