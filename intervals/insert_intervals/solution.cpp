#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()==0)
            return {newInterval};
        //binary search to see where we need to insert interval based on starting points of intervals
        int low = 0;
        int high = intervals.size()-1;
        int mid;
        int inserted_pos;
        while(low <= high){
            mid = low + (high - low)/2;
            if(newInterval[0]==intervals[mid][0]){
                if(newInterval[1] > intervals[mid][1]){
                    intervals[mid][1]=newInterval[1];
                    inserted_pos = mid;
                    break;
                } else {
                    return intervals;
                }
            }
            else if(newInterval[0] > intervals[mid][0]){
                low = mid + 1;
                if(high<low){
                    // we need to insert after mid
                    if(mid==intervals.size()-1){
                        intervals.push_back(newInterval);
                        inserted_pos = intervals.size()-1;
                    } else {
                        intervals.insert(intervals.begin() + mid + 1, newInterval);
                        inserted_pos = mid + 1;
                    }
                    break;
                }
            } else {
                high = mid - 1;
                if(high<low){
                    // we need to insert before mid
                    if(mid==0){
                        intervals.insert(intervals.begin(), newInterval);
                        inserted_pos = 0;
                    } else {
                        intervals.insert(intervals.begin() + mid, newInterval);
                        inserted_pos = mid;
                    }
                    break;  
                }
            }
        }
        // check if we need to merge with the next interval due to overlapping
        vector<vector<int>> result;
        for(int i = 0; i < intervals.size(); i++){
            if(i < inserted_pos){ // we dont need to worry about overlaps for indexes before the inserted position
                result.push_back(intervals[i]);
                continue;
            }
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