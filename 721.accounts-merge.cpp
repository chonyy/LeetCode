/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> owner;
        unordered_map<string, string> parents;
        unordered_map<string, set<string>> unions;

        for(auto act : accounts) {
            for(int i = 1; i < act.size(); i ++) {
                parents[act[i]] = act[i];
                owner[act[i]] = act[0];    
            }
        }

        for(auto act : accounts) {
            string parent = find(act[1], parents);
            for(int i = 2; i < act.size(); i ++) {
                parents[find(act[i], parents)] = parent;
            }
        }

        for(auto act : accounts) {
            for(int i = 1; i < act.size(); i ++)
                unions[find(act[i], parents)].insert(act[i]);
        }

        vector<vector<string>> res;
        for(auto u : unions) {
            vector<string> emails(u.second.begin(), u.second.end());
            emails.insert(emails.begin(), owner[u.first]);
            res.push_back(emails);
        }

        return res;
    }

    string find(string mail, unordered_map<string,string> parents) {
        return parents[mail] == mail ? mail : find(parents[mail], parents);
    }
};
// @lc code=end

