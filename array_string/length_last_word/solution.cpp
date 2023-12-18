#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int space_count = 0;
        for(int i = s.size()-1; i >=0; i--){
            if(space_count>=0 && length>0 && s[i]==' ')
                return length;
            if(s[i]!=' ')
                length++;
            else {
                space_count++;
            } 
        }
        return length;
    }
};