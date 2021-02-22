/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache {
public:
    stack<int> stk;
    unordered_map<int, int> cache;
    int _capacity;
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        
    }
    
    void put(int key, int value) {
        // already in cache
        if(m.find(key) != m.end()) {
            m[key] = value;
        }
        else {
            if(cache.size() == _capacity) {
                
            }

        }

        // not in cahche
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

