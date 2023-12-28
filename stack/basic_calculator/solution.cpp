#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * The idea here is to keep track of the result as we iterate through the string,
     * if we encounter an open parentheses we will use a stack to store the state of the result 
     * prior to encountering the parentheses and reset the result to compute the result within the parentheses.
     * then once we encounter the corresponding closing parentheses we will add our computed result 
     * with the result we had prior to encountering the parentheses.
    */
    int calculate(string s) {
        int cur = 0;
        int res = 0;
        int sign = 1; // handle additon/subtration: 1 = +, -1 = -
        vector<int> stack; // to handle parentheses
        for(auto el : s){
            if(isdigit(el)){
                cur = cur * 10 + ((int)el-48); // add each digit to cur
            } else if(el=='+' || el=='-'){ // check if we encounter an operator
                res += sign * cur; //apply the computation of the previous values
                el=='+' ? sign=1 : sign=-1; // update sign
                cur = 0; // reset cur
            } else if(el=='('){ // if we encounter an open parentheses we add our previous state (res, sign) into the stack
                stack.push_back(res);
                stack.push_back(sign);
                sign = 1; // reset sign
                res = 0; // reset result
            } else if(el==')'){ // if we encounter a closing parentheses we compute our current result and our previous result from the stack
                res += sign * cur;
                res *= stack.back(); // get the previous sign from the stack
                stack.pop_back();
                res += stack.back(); // get the previous result
                stack.pop_back();
                cur = 0; // reset cur
            }
        }
        return res + sign * cur; //once we reach the we compute our result once more in case there is a left over cur & sign value
    }
};