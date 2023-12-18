#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() < needle.size())
            return -1;
        int p;
        int start;
        for(int i  = 0; i < haystack.size(); i++){
            p = 0;
            if(haystack[i]==needle[0]){
                start = i;
                p = 0;
                while(p < needle.size() && (i+ p) < haystack.size()){
                    if(haystack[i+p] != needle[p]){
                        break;
                    } else {
                        p++;
                    }
                    if(p==needle.size())
                        return start;
                }
            }
        }
        return -1;
    }
};