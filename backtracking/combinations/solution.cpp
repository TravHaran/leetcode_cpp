#include <vector>
using namespace std;

class Solution {
    // Time: O(n^k)
    // Space: O(k + n^k)
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> comb = {};
        backtrack(comb, 1, n, k, result);
        return result;
    }

    void backtrack(vector<int>& combination, int i, int& n, int& k, vector<vector<int>>& result){
        if(combination.size()==k){
            vector<int> newCombination = combination;
            result.push_back(newCombination);
            return;
        }
        for(int j = i; j <= n; j++){
            combination.push_back(j);
            backtrack(combination, j+1, n, k, result);
            combination.pop_back();
        }
    }
};