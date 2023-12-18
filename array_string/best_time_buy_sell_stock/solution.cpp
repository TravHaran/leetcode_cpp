#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = INT32_MIN;
        int currP = 0;
        int minPrice = prices[0];
        for(int i = 0; i < prices.size(); i++){
            minPrice = min(minPrice, prices[i]);
            currP = prices[i] - minPrice;
            maxP = max(maxP, currP);
        }
        return maxP;
    }
};