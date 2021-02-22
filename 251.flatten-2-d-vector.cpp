/*
 * @lc app=leetcode id=251 lang=cpp
 *
 * [251] Flatten 2D Vector
 */

// @lc code=start
class Vector2D {
public:
    queue<int> q;
    Vector2D(vector<vector<int>>& v) {
        for(auto vv : v) {
            for(int num : vv)
                q.push(num);
        }
    }
    
    int next() {
        int ans = q.front();
        q.pop();
        return ans;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

