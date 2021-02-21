/*
 * @lc app=leetcode id=251 lang=cpp
 *
 * [251] Flatten 2D Vector
 */

// @lc code=start
class Vector2D {
    vector<vector<int>> :: iterator start, end;
    int cur = 0;
public:
    Vector2D(vector<vector<int>>& v) {
        start = v.begin();
        end = v.end();
    }
    
    int next() {
        hasNext();
        return (*start)[cur++];
    }
    
    bool hasNext() {
        while(start != end && cur == (*start).size()) {
            *start ++;
            cur = 0;
        }
        return start != end;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

