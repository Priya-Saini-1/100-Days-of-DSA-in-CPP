// Leetcode 18
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) { // TC: O( n log n + n^3) SC: O( unique groups)
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;

            for(int j=i+1; j<n;) {
                int p = j+1, q = n-1;

                while(p <  q) {
                    long long sum = (long long) nums[i] + (long long) nums[j] + (long long) nums[p] + (long long) nums[q];

                    if(sum < target) {
                        p++;
                    } else if(sum > target) {
                        q--;
                    } else {
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++; q--;

                        while(p < q && nums[p] == nums[p-1]) p++;
                    }
                }

                j++;
                while(j<n && nums[j] == nums[j-1]) j++;
            }
        }

        return ans;
    }

    vector<vector<int>> fourSumMethod2(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 4) return result;

        sort(nums.begin(), nums.end()); // Step 1: Sort the array

        // Step 2: Fix first two numbers (i and j)
        for (int i = 0; i < n - 3; i++) {
            // Avoid duplicate 'i' values
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {
                // Avoid duplicate 'j' values
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                long long newTarget = (long long)target - nums[i] - nums[j];
                int left = j + 1, right = n - 1;

                // Step 3: Two-pointer approach for remaining two numbers
                while (left < right) {
                    long long sum = nums[left] + nums[right];

                    if (sum == newTarget) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Skip duplicate pairs
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    } 
                    else if (sum < newTarget) {
                        left++;
                    } 
                    else {
                        right--;
                    }
                }
            }
        }

        return result;
    }
};