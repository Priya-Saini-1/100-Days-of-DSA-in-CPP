// Leetcode 31
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1, n = nums.size();

        for(int i= n-1; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                pivot = i;
                break;
            }
        }

        if(pivot == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        // 2nd step: next larger element
        for(int i = n-1; i > pivot; i--){
            if(nums[i] > nums[pivot]){
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // step 3: reverse (pivot + 1 to n-1) 
        // reverse(nums.begin() + pivot + 1, nums.end());
        int i = pivot+1, j = n-1;
        while(i <= j){
            swap(nums[i++], nums[j--]);
        }
    }
};