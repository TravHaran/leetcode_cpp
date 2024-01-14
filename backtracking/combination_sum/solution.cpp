#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        backtrack(0, {}, 0, target, candidates, result);
        return result;
    }
    void backtrack(int i, vector<int> combination, int total, int& target, vector<int>& candidates, vector<vector<int>>& result){
        if(total==target){ //base case 1
            vector<int> copy = combination;
            result.push_back(copy);
            return;
        }
        if(i >= candidates.size() || total > target) return; //base case 2
        combination.push_back(candidates[i]);
        backtrack(i, combination, total + candidates[i], target, candidates, result);
        combination.pop_back(); // clean up
        backtrack(i+1, combination, total, target, candidates, result); // move to next decision
    }
};