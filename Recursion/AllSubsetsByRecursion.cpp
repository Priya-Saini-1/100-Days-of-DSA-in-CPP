// // Leetcode 78 Subsets: we have to return the vector that stores all subsets
// #include <iostream>
// #include <vector>
// using namespace std;

// void printSubsets(vector<int> &arr, vector<int> &ans, int i) {
//     if(i == arr.size()) {
//         cout << "{ " ;
//         for(int val : ans) {
//             cout << val << " ";
//         }
//         cout << "}" << endl;
//         return;
//     }

//     //include
//     ans.push_back(arr[i]);
//     printSubsets(arr, ans, i+1);

//     ans.pop_back();
//     // exclude
//     printSubsets(arr, ans, i+1);
// }

// int main() {
//     vector<int> arr = {1, 2, 3};
//     vector<int> ans; // store subsets

//     printSubsets(arr, ans, 0);
//     return 0;
// }

// class Solution {
// public:
//     void getAllSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& AllSubsets) {
//         if(i == nums.size()) {
//             AllSubsets.push_back({ans});
//             return;
//         }

//         //include
//         ans.push_back(nums[i]);
//         getAllSubsets(nums, ans, i+1, AllSubsets);

//         ans.pop_back();
        
//         // exclude
//         getAllSubsets(nums, ans, i+1, AllSubsets);
//     }

//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> AllSubsets;
//         vector<int> ans;

//         getAllSubsets(nums, ans, 0, AllSubsets); 
//         return AllSubsets;
//     }
// };

// Leetcode 90 Subset II
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void getAllSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSubsets) {// TC O(2^n * n)
        if(i == nums.size()) {
            allSubsets.push_back(ans);
            return;
        }

        // include
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i+1, allSubsets);

        ans.pop_back();

        int idx = i+1;
        while(idx < nums.size() && nums[idx] == nums[idx-1] ) idx++;

        // exclude
        getAllSubsets(nums, ans, idx, allSubsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> allSubsets;
        vector<int> ans;

        getAllSubsets(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};