#include <iostream>
#include <vector>
using namespace std;

bool IsValid(vector<int> &arr, int n, int m, int maxAllowedPages){
    int student=1, pages=0;

    for(int i = 0; i < n; i++){
        if(arr[i] > maxAllowedPages){
            return false;
        }

        if(pages + arr[i] <= maxAllowedPages){
            pages += arr[i];
        } else {
            student++;
            pages = arr[i];
        }
    }
    return student > m ? false : true;
}

int allocateBooks(vector<int> &arr, int n, int m) {// O(log N * n)
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }

    cout << "sum : " << sum <<endl;

    int ans = -1;
    int st=0, end=sum; // range of possible ans

    while(st <= end){
        int mid = st + (end-st)/2;
        cout << "mid: " << mid <<endl;

        if(IsValid(arr, n, m, mid)){ // left
            ans = mid;
            end = mid - 1;
        } else { // right
            st = mid + 1;
        }
    }
    cout << "ans: " << ans << endl;
    return ans;
}

int main() {
    // vector<int> arr1 = {2, 1, 3, 4};
    vector<int> arr = {15, 17, 20}; // 32
    int n = 4, m = 2;

    cout << allocateBooks(arr, n, m) << endl;
    return 0;
}