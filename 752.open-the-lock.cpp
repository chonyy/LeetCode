/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */

// @lc code=start
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deads(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        unordered_set<string> begin, end;

        if (deads.count("0000")) return -1;
        if (target == "0000") return 0;

        begin.insert("0000");
        end.insert(target);
        visited.insert("0000");
        int steps = 0;

        while(!begin.empty() && !end.empty()) {
            if(begin.size() > end.size())
                swap(begin ,end);
            unordered_set<string> pass;
           for(auto cur : begin){ 
                for(string neighbor : getNeighbors(cur)) {
                    if(end.count(neighbor))
                        return steps + 1;
                    // if it's a deadend
                    if(deads.find(neighbor) != deads.end())
                        continue;
                    // if visited
                    if(visited.find(neighbor) != visited.end())
                        continue;

                    visited.insert(neighbor);
                    pass.insert(neighbor);
                }
           }
           swap(begin, pass);
            steps ++;
        }

        return -1;
    }

    // 8 choices
    // 4 digits * (increment, decrease)
    vector<string> getNeighbors(string s) {
        vector<string> neighbors;

        for(int i = 0; i < 4; i ++) {
            char digit = s[i];
            string s1 = s.substr(0, i) + (digit == '9' ? '0' : char(digit + 1)) + s.substr(i+1); 
            string s2 = s.substr(0, i) + (digit == '0' ? '9' : char(digit - 1)) + s.substr(i+1); 
            neighbors.push_back(s1);
            neighbors.push_back(s2);
        }

        return neighbors;
    } 
};
// @lc code=end

