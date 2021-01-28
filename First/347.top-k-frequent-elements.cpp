/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int max_freq = 1;

        for(int num : nums) {
            max_freq = max(max_freq, ++count[num]);
        }

        unordered_map<int, vector<int>> bucket;

        for(auto i : count) {
            bucket[i.second].push_back(i.first);
        }

        vector<int> res;
        int num = 0;

        for(int i = max_freq; i >=1; i --) {
            if(num == k)
                return res;
            auto find = bucket.find(i);
            if(find == bucket.end())
                continue;
            else {
                res.insert(res.end(), find->second.begin(), find->second.end());
                num += find->second.size();
            }
        }
        return res;
    }
};
// @lc code=end

