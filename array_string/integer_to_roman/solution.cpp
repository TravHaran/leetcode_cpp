#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> numerals = {
            {1, "I"},
            {4, "IV"},
            {5, "V"},
            {9, "IX"},
            {10, "X"},
            {40, "XL"},
            {50, "L"},
            {90, "XC"},
            {100, "C"},
            {400, "CD"},
            {500, "D"},
            {900, "CM"},
            {1000, "M"}
        };
        string result;
        int max_base;
        int quotient;
        while(num > 0){
            max_base = 0;
            for(const auto &base : numerals){ // find the max base value for this number
                if(num >= base.first)
                    max_base = max(max_base, base.first);
            }
            // divide number by max base
            quotient = num / max_base;
            for(int i = 0; i < quotient; i++){
                result += numerals[max_base];
            }
            num = num % max_base;
        }   
        return result; 
    }
};

int main(){
    Solution solution;
    int num = 59;
    cout<<solution.intToRoman(num)<<endl;
}