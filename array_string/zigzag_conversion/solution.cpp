#include <string>
#include <assert.h>
#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows < 2)
            return s;
        string result;
        int p;
        int increment;
        for(int i = 0; i < numRows; i++){
          increment = 2*(numRows - 1); // how many jumps we need to take to reach next element
          p = i;
          while(p < s.size()){
            result += s[p];
            // check if we are in a middle row in which we add the middle element defined by (increment - 2 * current row)
            if(i > 0 && i < numRows - 1 && (p + increment - 2 * i)<s.size()){
                result += s[p + increment - 2 * i];
            }
            p += increment;
          }
        }
        return result;
        
    }
};

int main(){
    Solution solution;
    int numRows = 3;
    string s = "PAYPALISHIRING"; // expect: "PAHNAPLSIIGYIR"
    cout<<solution.convert(s, numRows)<<endl;
}