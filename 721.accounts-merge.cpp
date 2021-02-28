/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
 */

// @lc code=start
class Solution {
    unordered_map<string, string> owner;
    unordered_map<string, string> parents;
    unordered_map<string, set<string>> unions;
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        // init: parent is self
        // set up owner with the name
        for(auto act : accounts) {
            for(int i = 1; i < act.size(); i ++) {
                parents[act[i]] = act[i];
                owner[act[i]] = act[0];    
            }
        }

        // Set all related to the same parent, which is the first mail
        for(auto act : accounts) {
            string parent = find(act[1]);
            for(int i = 2; i < act.size(); i ++) {
                parents[find(act[i])] = parent;
            }
        }

        // Group the mails with the same parent
        for(auto act : accounts) {
            for(int i = 1; i < act.size(); i ++)
                unions[find(act[i])].insert(act[i]);
        }

        // Return result
        vector<vector<string>> res;
        for(auto u : unions) {
            vector<string> emails(u.second.begin(), u.second.end());
            emails.insert(emails.begin(), owner[u.first]);
            res.push_back(emails);
        }

        return res;
    }

    string find(string& mail) {
        return parents[mail] == mail ? mail : find(parents[mail]);
    }
};
// @lc code=end

