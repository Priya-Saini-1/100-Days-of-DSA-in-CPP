// Leetcode 74
#include <iostream>
#include <vector>
using namespace std;

// class Solution {
//     public:
//         bool searchInRow(vector<vector<int>> & mat,int target, int row){
//             int n = mat[0].size();
//             int st = 0, end = n - 1;

//             while(st <= end){
//                 int mid = st + (end - st)/2;
//                 if(target == mat[row][mid]){
//                     return true;
//                 } else if(target > mat[row][mid]) {
//                     st = mid + 1;
//                 } else {
//                     end = mid - 1;
//                 }
//             }
//             return false;
//         }

//         bool searchMatrix(vector<vector<int>> & matrix,int target){
//             // BS on tot rows
//             int m = matrix.size(), n = matrix[0].size();

//             int startRow = 0, endRow = m-1;
//             while(startRow <= endRow) {
//                 int midRow = startRow + (endRow - startRow)/2;

//                 if(target >= matrix[midRow][0] && target <= matrix[midRow][n-1]){
//                     // found the row
//                     return searchInRow(matrix, target, midRow);
//                 } else if(target >= matrix[midRow][n-1]){
//                     // down => right
//                     startRow = midRow + 1;
//                 } else {
//                     // up => left
//                     endRow = midRow - 1;
//                 }
//             }
//             return false;
//         }
// };

// leet code 240 Search in a 2D matrix ||

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int r = 0, c = n-1;

        while(c >= 0 && r < m){
            if(target == matrix[r][c]){
                return true;
            } else if ( target < matrix[r][c]){
                c--;
            } else {
                r++;
            }
        }
        return false;
    }
};