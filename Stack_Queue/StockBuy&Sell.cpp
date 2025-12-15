// buy and sell stocks based on previous price
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int min(int a, int b){ 
        return (a > b ? b : a);
    }
    int max(int a, int b){ 
        return (a > b ? a : b);
    }
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, bestBuy = prices[0];

        for (int i = 1; i < prices.size(); i++){
            if(prices[i] > bestBuy){
                maxProfit = max(maxProfit, (prices[i] - bestBuy));
            }
            bestBuy = min(bestBuy, prices[i]);
        }

        return maxProfit;
    }
};