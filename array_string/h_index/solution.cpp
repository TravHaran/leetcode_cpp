#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        // sort array in descending order
        sort(citations.begin(), citations.end(), std::greater<int>());
        // now a valid h_index occurs when the index is greater than or equal to it's citation value
        // simply return this value;
        // else return the number of papers
        int h = 0;
        for(int i = 0; i < citations.size(); i++){
            if(i >= citations[i])
                return i;
        }
        return citations.size(); 
    }
};