#include <vector>
#include <queue>
using namespace std;

class Solution {
    /**
     * 2 heap solutions...
     * We maintain a min heap for capital , max heap for only profit.
     * The min heap of capital will be pushed to the max heap profit,
     * which is the eligible/qualified projects to be selected.
    */
   // Time: O(k + logn), Space: O(n)
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int>maxHeap; // initialize a maxHeap of profits
        //create a minHeap of capital profit pairs
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>minHeap;

        for(int i = 0; i < capital.size(); i++){
            minHeap.push({capital[i], profits[i]});
        }

        for(int i = 0; i < k; i++){
            while(!minHeap.empty() && minHeap.top().first <= w){
                auto p = minHeap.top(); //add the profit of project with the lowest capital to the maxHeap
                minHeap.pop();
                maxHeap.push(p.second);
            }
            if(maxHeap.empty()){ // we cant pop from maxHeap if its empty
                break;
            }
            w += maxHeap.top(); //add the max profit
            maxHeap.pop();
        }
        return w;
    }
};