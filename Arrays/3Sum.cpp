// Leetcode 15 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSumBruteForce(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        set<vector<int>> s;  // set<uniqueTriplets>

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                for(int k = j+1; k < n; k++){
                    if(nums[i] + nums[j] + nums[k] == 0 ){
                        vector<int> trip = {nums[i] , nums[j], nums[k]};
                        sort(trip.begin(), trip.end());

                        if(s.find(trip) == s.end()){
                            s.insert(trip);
                            ans.push_back(trip);
                        }
                    }
                }
            }
        }

        return ans;
    }


    vector<vector<int>> threeSumHashing(vector<int>& nums) {
        int n = nums.size();
       

        set<vector<int>> UniqueTriplets;  

        for(int i = 0; i < n; i++){
            int tar = -nums[i];
            set<int> s;

            for(int j = i+1; j < n; j++){
                int third = tar - nums[j];

                if(s.find(third) != s.end()){
                    vector<int> trip = {nums[i], nums[j], third};
                    sort(trip.begin(), trip.end());
                    UniqueTriplets.insert(trip);
                }

                s.insert(nums[j]);
            }
        }

         vector<vector<int>> ans(UniqueTriplets.begin(), UniqueTriplets.end());
        return ans;
    }

    vector<vector<int>> threeSumTwoPointer(vector<int>& nums) { // TC O( n log n + n^2 ) & SC O( unique Triplets)
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end()); // O(n log n)

        for( int i=0; i<n; i++ ) {
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int j = i+1, k = n-1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0) {
                    j++;
                } else if(sum > 0) {
                    k--;
                } else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++; k--;

                    while(j < k && nums[j] == nums[j-1]) j++;
                }
            }
        }
        return ans;
    }
};