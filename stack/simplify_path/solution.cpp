#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string simple_path = "/";
        string cur = "";
        path += '/'; // adding an extra slash at the end makes it easy to check our cases in the for loop
        for(int i = 1; i < path.size(); i++){
            if(path[i]=='/'){ // we need to check cur & update stack
                if(cur==".."){ //check if we need to pop from stack
                    if(!stack.empty()){
                        stack.pop_back();
                    }
                } else if(cur!="" && cur != "."){ 
                    // if cur is empty it means we encountered consecutive '/'
                    // if cur is '.' it means we're referencing the current directory with '/./'
                    // we ignore the above cases
                    stack.push_back(cur);
                }
                // need to reset cur after updating stack
                cur = "";
            } else {
                cur += path[i];
            }
        }
        //add all directories from stack with '/' in between with no '/' at the end
        for(int i = 0; i < stack.size(); i++){
            simple_path += stack[i];
            if(i!=stack.size()-1) simple_path += '/';
        }
        return simple_path;  
    }
};