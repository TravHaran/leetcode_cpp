#include <unordered_map>
#include <vector>
#include <cstdlib>

class RandomizedSet {
private:
    std::unordered_map<int, int> values;
    std::vector<int> val_arr;
    int idx_count;

public:
    RandomizedSet() {
        idx_count = -1;
        
    }
    
    bool insert(int val) {
        if(values.count(val)==0){ //item doesn't exist
            idx_count++;
            values[val] = idx_count;
            val_arr.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(values.count(val)==0)
            return false;
        
        //swap last element of array with target element to remove and then pop in O(1) time
        int target_idx = values[val];
        int temp = val_arr[target_idx];
        val_arr[target_idx] = val_arr[idx_count];
        val_arr[idx_count] = temp;
        val_arr.pop_back();
        idx_count--;

        //update the value of the previous last element of the array in the hashmap
        values[val_arr[target_idx]] = target_idx;
        values.erase(val);
        return true;   
    }
    
    int getRandom() {
        return val_arr[rand()%val_arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */