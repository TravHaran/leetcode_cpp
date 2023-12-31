#include <unordered_map>
using namespace std;

class LRUCache {
private:
    struct ListNode {
        int val;
        int key;
        ListNode *next;
        ListNode *prev;
        ListNode() : key(0), val(0), next(nullptr), prev(nullptr) {}
        ListNode(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
    };

    ListNode* head = new ListNode();
    ListNode* tail = new ListNode();
    unordered_map<int, ListNode*> cache_map = {};
    int capacity;

    void remove(ListNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void add(ListNode* node){ // add to tail of list
        tail->prev->next = node;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail; // real head is head->next
        tail->prev = head; // real tail is tail->prev
    }
    
    int get(int key) {
        //check if key exists in cache
        if(cache_map.count(key)){
            ListNode* target = cache_map[key];
            //we need to move the target node to tail
            remove(target);
            add(target);
            return target->val;
        }
        return -1; 
    }
    
    void put(int key, int value) {  
        //check if the key already exists in the cache
        if(cache_map.count(key)){
            ListNode* target = cache_map[key];
            remove(target); 
        }
        // add to cache
        ListNode* target = new ListNode(key, value);
        cache_map[key] = target;
        add(target);
        if(cache_map.size() > capacity){
            // we need to remove LRU key
            ListNode* LRU_Node = head->next;
            cache_map.erase(LRU_Node->key);
            remove(LRU_Node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */