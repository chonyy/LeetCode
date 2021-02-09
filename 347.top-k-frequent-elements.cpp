/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int > m;
        vector<int> res;

        for(int num : nums) {
            m[num] ++;
        }

        priority_queue<pair<int, int>> pq;

        for(auto it = m.begin(); it != m.end(); it ++) {
            pq.push({it->second, it->first});
            cout << it->first << endl;
            if(pq.size() > m.size()-k) {
                auto top = pq.top();
                pq.pop();
                res.push_back(top.second);
            }
        }

        return res;
    }
};
// @lc code=end

