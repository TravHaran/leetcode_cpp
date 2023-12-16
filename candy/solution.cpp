#include <vector>
#include <assert.h>
using namespace std;

class Solution {
    /**
     * two pass approach:
     * in first pass ensure that if rating is greater than left neighbor, child receives more candy
     * in second pass ensure that if rating is greater than right neightbor, child receives more candy
    */
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candy = ratings;
        for(int i = 0; i < n; i++)
            candy[i] = 1;
        for(int i = 1; i < n; i++){ //check left neighbor
            if(ratings[i] > ratings[i-1])
                candy[i] = candy[i-1] + 1;
        }
        for(int i = n-2; i >=0; i--){ //check right neighbor
            if(ratings[i] > ratings[i+1])
                candy[i] = max(candy[i], candy[i+1] + 1); // we dont wan't to decrease the candy given just cuz the right neihbor has higher rating
        }
        int sum = 0;
        for(const auto val : candy){
            sum += val;
        }
        return sum;
    }
};

int main(){
    Solution solution;
    vector<int> ratings = { 1, 0, 2 };
    assert(solution.candy(ratings)==5);

}