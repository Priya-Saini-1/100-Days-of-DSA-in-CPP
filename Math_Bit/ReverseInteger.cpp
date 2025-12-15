// Leetcode 7
#include <iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int revNum = 0;

        while (x != 0){
            int r = x % 10;
            if(revNum > INT64_MAX / 10 || revNum < INT64_MIN / 10){
                return 0;
            }
            revNum = (revNum * 10) + r;
            x /= 10;
        }

        return revNum;
    }
};