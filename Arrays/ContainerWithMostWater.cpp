#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int lp=0, rp=height.size()-1;

        while(lp < rp){
            int w = rp - lp;
            int h = min(height[lp], height[rp]);
            int area = w * h;

            maxWater = max(maxWater, area);
            height[lp] < height[rp] ? lp++ : rp--;
        }
        
        return maxWater;
    }
};