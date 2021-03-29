/*
 * @lc app=leetcode id=1152 lang=cpp
 *
 * [1152] Analyze User Website Visit Pattern
 */

// @lc code=start
class Solution {
public:
    // joe: {1: "home", 2: "about", 3: "career"}
    unordered_map<string, map<int, string>> m;
    unordered_map<string, int> count;
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        // Store all the activities in the map
        for(int i = 0; i < username.size(); i ++) {
            m[username[i]].insert({timestamp[i], website[i]});
        }

        // Count all the  3 sequences
        for(auto e : m) {
            auto seq = e.second;
            unordered_set<string> visited;
            for(auto it = seq.begin(); it != seq.end(); it ++)
                for(auto it1 = next(it); it1 != seq.end(); it1 ++)
                    for(auto it2 = next(it1); it2 != seq.end(); it2 ++) {
                        string key = it->second + '$' + it1->second + '#' + it2->second;
                        visited.insert(key);
                    }
            for(auto vis : visited)
                count[vis] ++;
        }

        // get the maximum sequence with the most count
        string resStr = "";
        int curMax = 0;
        for(auto cnt : count) {
            if(cnt.second >= curMax) {
                if(resStr == "") {
                    resStr = cnt.first;
                }
                else
                    resStr = cnt.second > curMax ? cnt.first : min(resStr, cnt.first);

                curMax = cnt.second;
            }
        }

        auto split1 = resStr.find('$');
        auto split2 = resStr.find('#');

        return {resStr.substr(0, split1), resStr.substr(split1+1, split2 - split1 - 1), resStr.substr(split2+1)};
    }
};
// @lc code=end

