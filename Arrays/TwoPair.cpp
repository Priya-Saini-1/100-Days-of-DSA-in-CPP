#include <iostream>
#include <vector>
using namespace std;

vector<int> pairSum(vector<int> nums, int target){
    for(int i = 0; i < nums.size(); i++){
        for(int j = i+1; j < nums.size(); j++){
            if ( nums[i] + nums[j] == target){
                return {i, j};
            }
        }
    }
}

vector<int> pairSum_approach2(vector<int> nums, int target){
    int n = nums.size();
    int i = 0 , j =  n-1;

    while (i < j){
        if ( (nums[i] + nums[j]) > target) j--;
        else if ( (nums[i] + nums[j]) < target) i++;
        else return {i, j};
    }
}

int main(){
    vector<int> nums = {3, 2, 4};
    int target = 6;
    
    vector<int> ans1 = pairSum(nums, target);
    vector<int> ans2 = pairSum_approach2(nums, target);

    cout << "Ans by approach 1"<< endl;
    cout << " ( " << ans1[0] << " , " << ans1[1] << " )" <<endl;
    
    cout << "Ans by approach 2"<< endl;
    cout << " ( " << ans2[0] << " , " << ans2[1] << " )" <<endl;

    return 0;
}