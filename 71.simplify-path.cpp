/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stk;
        string temp, res;
        stringstream ss(path);
        while(getline(ss, temp, '/')) {
            if(temp == "" || temp == ".")
                continue;
            if(temp == ".." && !stk.empty())
                stk.pop_back();
            else if(temp != "..")
                stk.push_back(temp);
        }

        for(string dir : stk)
            res += '/' + dir;

        return stk.empty() ? "/" : res;
    }
};
// @lc code=end

