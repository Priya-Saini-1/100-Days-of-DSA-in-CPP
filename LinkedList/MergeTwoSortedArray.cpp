// Problem 88 Leetcode
// Example 1:
// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int idx= m+n-1, i = m-1, j = n-1;

        while(i >=0 && j >= 0){
            if(A[i] >= B[j]) {
                A[idx--] = A[i--];
            } else {
                A[idx--] = B[j--];
            }
        }
        while ( j >= 0 ){
            A[idx--] = B[j--];
        }
    }
};