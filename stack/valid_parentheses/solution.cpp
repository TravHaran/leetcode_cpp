#include <string>
#include <deque>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        deque<char> open_brackets;
        unordered_map<char, char> bracket_map = {
            {')', '('},
            {'}', '{'},
            {']', '['},
        };
        for(auto bracket : s){
            if(open_brackets.empty()){
                if(bracket_map.count(bracket)) return false; // can't have a closing bracket when stack empty
                open_brackets.push_back(bracket);
            } else {
                if(!bracket_map.count(bracket)) open_brackets.push_back(bracket); //push open brackets into strack
                else{ // current elemnt is a closing bracket
                    if(open_brackets.back()==bracket_map[bracket]) open_brackets.pop_back();
                    else { // closing bracket doesnt match corresponding open bracket at top of stack
                        return false;
                    }
                }
            }   
        }
        if(open_brackets.empty()) return true;
        return false;   
    }
};