#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> result;
        unordered_map<char, int> t_map;
        for(const auto el : t){
            t_map[el]++;
        }
        int need = t.size();
        int have = 0;
        int min_len = INT32_MAX;
        int window_size;
        unordered_map<char, int> window_map;
        int start = 0;
        for(int i = 0; i < s.size(); i++){
            window_map[s[i]]++;
            if(t_map.count(s[i]) && window_map[s[i]]<=t_map[s[i]]){
                have++;
            }
            while(have==need){
                //update result
                window_size = i - start + 1;
                if(window_size < min_len){
                    result = {start, window_size};
                    min_len = window_size;
                }
                window_map[s[start]]--;
                if(t_map.count(s[start]) && window_map[s[start]] < t_map[s[start]])
                    have--;
                start++;
            }
        }
        return min_len != INT32_MAX ? s.substr(result[0], result[1]) : "";
    }
};

int main(){
    Solution solution;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout<<solution.minWindow(s, t)<<endl;
}