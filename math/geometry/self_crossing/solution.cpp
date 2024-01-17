#include <vector>
using namespace std;

class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        // if number of elemnts is less than 4 then it can't complete a full circle
        if(distance.size()<4) return false;
        // a crossing only happens in three cases
        for(int i = 3; i < distance.size(); i++){
            //case 1
            if(distance[i-3]>=distance[i-1] && distance[i-2]<=distance[i]) return true;
            //case 2
            if(i>3){
                if(distance[i-1]==distance[i-3] && (distance[i-4] + distance[i]) >= distance[i-2]) return true;
            }
            //case 3
            if(i>4){
                if(distance[i-3]>=distance[i-1] && distance[i-2]>=distance[i-4] && 
                (distance[i-1]+distance[i-5])>=distance[i-3] && (distance[i]+distance[i-4])>=distance[i-2]) return true;
            }
        }
        return false;
    }
};