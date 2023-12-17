#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // reverse whole string
        reverse(s.begin(), s.end());
        // reverse word by word
        char temp;
        int end;
        int l = 0;
        int r;
        while(l < s.size()){
            if(s[l]==' '){
                l++;
            } else {
                r = l;
                //now we set the r pointer
                while(r<s.size() && s[r]!=' '){
                    r++;
                } 
                end = r; 
                r--;  
                //now we swap r & l
                while(l < r){
                    temp = s[r];
                    s[r] = s[l];
                    s[l] = temp;
                    l++;
                    r--;
                }
                l = end;  
            }
        }

        //trim starting white space
        while(s[0]==' '){
            s.erase(s.begin());
        }
        //trim trailing white space
        while(s[s.size()-1]==' '){
        s.erase(s.end()-1);
        }
        
        //remove multiple space values from string
        int i = 0;
        while(i < s.size()-1){
            while(s[i]==' ' && s[i+1]==' '){
                s.erase(s.begin()+i);
            }
            i++;   
        }
        return s;
    }
};