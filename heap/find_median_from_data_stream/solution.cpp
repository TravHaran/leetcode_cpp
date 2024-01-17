#include <queue>
using namespace std;

class MedianFinder {
    // Time: O(logn)
    // Space: O(n)
public:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
    MedianFinder() {
        // two heaps, large, small, minHeap, maxHeap
        // heaps should be equal size
        small = {};
        large = {};
        
    }
    
    void addNum(int num) {
        // insert num into small heap
        small.push(num);
        // make sure that every num in small is <= every num in large
        if(!small.empty() && !large.empty() && small.top() > large.top()){
            int val = small.top();
            small.pop();
            large.push(val);
        }
        // check if size is uneven
        if(small.size() > large.size() + 1){
            int val = small.top();
            small.pop();
            large.push(val);
        }
        if(large.size() > small.size() + 1){
            int val = large.top();
            large.pop();
            small.push(val);
        }
    }
    
    double findMedian() {
        //case 1: odd length
        if(small.size() > large.size()){
            return small.top();
        } else if(large.size() > small.size()){
            return large.top();
        }
        //case2: even length
        return (double)(small.top()+large.top())*0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */