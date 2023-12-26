#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        int result;
        int a;
        int b;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i]=="+" ||
                tokens[i]=="-" ||
                tokens[i]=="*" ||
                tokens[i]=="/"){
                b = stack.back();
                stack.pop_back();
                a = stack.back();
                stack.pop_back();
                if(tokens[i]=="+"){
                    result = (a + b);
                } else if(tokens[i]=="-"){
                    result = (a - b);
                } else if(tokens[i]=="*"){
                    result = (a * b);
                } else if(tokens[i]=="/"){
                    result = (a / b);
                }
                stack.push_back(result);
            } else {
                stack.push_back(stoi(tokens[i]));
            }
        }
        return stack.back();
    }
};