/*
 * @lc app=leetcode id=1481 lang=cpp
 *
 * [1481] Least Number of Unique Integers after K Removals
 */

// @lc code=start
class Solution {
public:

    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // sort the array with occurence
        unordered_map<int, int> m;
        for(int num : arr)
            m[num] ++;
        auto compare = [](const pair<int, int> p1, const pair<int, int> p2) {
            if(p1.second == p2.second) 
                return p1.first > p2.first;
            return p1.second > p2.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);

        for(auto it = m.begin(); it != m.end(); it ++) {
            pq.push({it->first, it->second});
        }

        for(int i = 0; i < k; i ++) {
            if(pq.top().second)
                pq.top().second --;
            else
                pq.pop();
        }

        return pq.size();;
    }
};
// @lc code=end

