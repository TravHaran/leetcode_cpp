#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        //only add open parenthesis if open < n
        //only add a closing parenthesis if closed < open
        //valid IIF open==closed==n
        vector<char> stack;
        vector<string> res;
        backtrack(0, 0, n, stack, res);
        return res;
    }

    void backtrack(int openN, int closeN, int& n, vector<char>& stack, vector<string>& res){
        if(openN==closeN && openN==n){
            string validParenthesis = "";
            for(auto c : stack){
                validParenthesis += c;
            }
            res.push_back(validParenthesis);
            return;
        }
        if(openN < n){
            stack.push_back('(');
            backtrack(openN+1, closeN, n, stack, res);
            stack.pop_back();
        }
        if(closeN < openN){
            stack.push_back(')');
            backtrack(openN, closeN+1, n, stack, res);
            stack.pop_back();
        }
    }
};