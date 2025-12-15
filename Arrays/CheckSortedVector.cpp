#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSorted(vector<int> arr, int n) { 
        if (n == 0 || n == 1){
            return true;
        }

        return arr[n-1] >= arr[n-2] && isSorted(arr, n-1);
}



int main(){
    int n;
    vector<int> arr = {1, 4, 3, 2};
    sort(arr.begin(), arr.end());

    cout << "0 for false and 1 for true" << endl;
    cout << "IsSorted  " <<  isSorted(arr, arr.size()) << endl;
    return 0;
}