#include <vector>
using namespace std;

class MinStack {
private:
    vector<pair<int, int>> minStack; // every node index in stack to it's prev Min val
    int minVal;
public:
    MinStack() {
        minStack = {};
        minVal = INT32_MAX; 
    }
    
    void push(int val) {
        minStack.push_back({val, minVal});
        minVal = min(minVal, val); 
    }
    
    void pop() {
        minVal = minStack.back().second;
        minStack.pop_back(); 
    }
    
    int top() {
       return minStack.back().first;
    }
    
    int getMin() {
        return minVal;    
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */