#include <iostream>
#include <vector>
using namespace std;

bool IsPossible(vector<int> &arr, int n, int m, int maxAllowedPages){
    int painters=1, time=0;

    for(int i = 0; i < n; i++){
        if(arr[i] > maxAllowedPages){
            return false;
        }

        if(time + arr[i] <= maxAllowedPages){
            time += arr[i];
        } else {
            painters++;
            time = arr[i];
        }
    }
    return painters > m ? false : true;
}

int minTimeToPaint(vector<int> &arr, int n, int m) {// O(log N * n)
    int sum = 0, maxVal = INT32_MAX;
    for(int i=0; i<n; i++){
        sum += arr[i];
        maxVal = max(maxVal, arr[i]);
    }

    int ans = -1;
    int st = 0, end=sum; // range of possible ans

    while(st <= end){
        int mid = st + (end-st)/2;

        if(IsPossible(arr, n, m, mid)){ // left
            ans = mid;
            end = mid - 1;
        } else { // right
            st = mid + 1;
        }
    }

    return ans;
}

int main() {
    // vector<int> arr1 = {2, 1, 3, 4};
    vector<int> arr = {40, 30, 10, 20}; // 32
    int n = 4, m = 2;

    cout << minTimeToPaint(arr, n, m) << endl;
    return 0;
}