/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

// @lc code=start
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;

        for(string word : words) {
            count[word] ++;
        }

        typedef pair<string, int> Node;

        auto comp = [](Node& a, Node& b) {
            if(a.second == b.second)
                return a.first < b.first;
            return a.second > b.second;
        };

        priority_queue<Node, vector<Node>, decltype(comp)> q(comp);

        for(auto i : count) {
            q.push(i);
            if(q.size() > k) q.pop();
        }

        vector<string> res;

        while(!q.empty()) {
            res.push_back(q.top().first);
            q.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

