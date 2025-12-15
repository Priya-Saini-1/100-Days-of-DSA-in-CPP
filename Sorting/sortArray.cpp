// sort array of 0's, 1's and 2's 
// leetcode Problem 75 sort colors
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Brute force
class Solution_By_BruteForce { // O(nlogn)
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};
// Optimized approach
class Solution_optimized {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int count0=0, count1=0, count2=0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                count0++;
            } else if(nums[i] == 1){
                count1++;
            } else if(nums[i] == 2){
                count2++;
            }
        }
        int idx=0;
        for(int i = 0; i < count0; i++){
            nums[idx++] = 0;
        }
        for(int i = 0; i < count1; i++){
            nums[idx++] = 1;
        }
        for(int i = 0; i < count2; i++){
            nums[idx++] = 2;
        }
    }
};
// most optimal approach
// Dutch national flag algorithm
 class Most_Optimal_Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low=0, mid=0, high=n-1;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                mid++, low++;
            } else if(nums[mid] == 1){
                mid++;
            } else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

void print(vector<int> nums){
    cout << "\nArray: ";
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " " ;
    }

}

int main(){
    Solution_By_BruteForce b;
    Solution_optimized s;
    Most_Optimal_Solution sol;
    vector<int> nums = {2, 1, 0, 1, 2, 0};
    vector<int> temp = nums;

    cout <<"Before sorting ";
    print(nums);

    cout << "\n\nAfter sorting";
    b.sortColors(nums);
    cout << "\nBy BruteForcce ";
    print(nums);

    nums = temp;

    s.sortColors(nums);
    cout << "\nBy Optimized way ";
    print(nums);

    nums = temp;

    b.sortColors(nums);
    cout << "\nBy Most optimized way ";
    print(nums);

    return 0;
}