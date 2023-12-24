#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < intervals.size(); i++){
            if(i==0)
                result.push_back(intervals[0]);
            else if(intervals[i][0] <= result[result.size()-1][1]){ 
                if(result[result.size()-1][1] < intervals[i][1]){
                    result[result.size()-1][1] = intervals[i][1];
                } 
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};