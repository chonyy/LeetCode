/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        const auto it = m.find(key);
        if(it == m.end()) 
            return -1;
        else {
            // move key to the front
            cache.splice(cache.begin(), cache, it->second);
        }
        return it->second->second;
    }
    
    void put(int key, int value) {
        const auto it = m.find(key);

        // if already exist
        if(it != m.end()) {
            it->second->second = value;
            cache.splice(cache.begin(), cache, it->second);
            return;
        }
        else { // does not exist
            // if max capacity, remove the oldest
            if(cache.size() == _capacity) {
                auto node = cache.back();
                m.erase(node.first);
                cache.pop_back();
            }

            cache.emplace_front(key, value);
            m[key] = cache.begin();
        }
    }
private:
    int _capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> m;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

