#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set <int> happySet;
        int updated_n;
        while(n != 1){
            updated_n = 0;
            happySet.insert(n);
            while(n >0){ // get digits
                updated_n += pow(n % 10, 2);
                n /= 10;
            }
            n = updated_n;
            if(happySet.count(n)) return false;
        }
        return true;
    }
};