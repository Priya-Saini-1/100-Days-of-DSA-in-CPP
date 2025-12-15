#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n = 7;
    int arr[] = { 3, -4, 5, 4, -1, 7, -8 };

    int curr = 0, maxSum = INT32_MIN;

    for ( int i = 0; i < n; i++){
        curr += arr[i];
        maxSum = max(curr, maxSum);
        if ( curr < 0 ){
            curr = 0;
        }
    }
    cout << "Max of sum of subarray by Kadane's Algo is : " << maxSum << endl;
    return 0;
}