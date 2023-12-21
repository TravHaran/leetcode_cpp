#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
/**
 * NOT COMPLETE
*/
class Solution {
private:
    int getHave(const unordered_map<char, int> t_map, const unordered_map<char, int> win_map){
        int have_count = 0;
        for(const auto [key, value] : t_map){
            if(win_map[key] >= value) have_count++;
        }
        return have_count;
    }
public:
    string minWindow(string s, string t) {
        string result;
        unordered_map<char, int> t_map;
        for(const auto el : t){
            t_map[el]++;
        }
        int need = t.size();
        int i = 0;
        int cur;
        int min_len = INT32_MAX;
        int window_size;
        unordered_map<char, int> window_map;
        while(i< s.size()){
            if(t_map.count(s[i])!=0) {
                cur = i;
                while(cur < s.size()){
                    if(t_map.count(s[i])!=0)
                        window_map[s[cur]]++;
                    while(getHave()==need){
                        window_map[s[i]]--;
                        if(window_map[s[i]]==0) window_map.erase(s[i]);
                        window_size = cur - i + 1;
                        min_len = min(min_len, window_size);
                        if(window_size==min_len) result = s.substr(i, window_size);
                        i++;
                    }
                }
            }
        }
        return result;
    }
};

int main(){
    Solution solution;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout<<solution.minWindow(s, t)<<endl;
}