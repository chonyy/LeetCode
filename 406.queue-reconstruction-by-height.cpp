/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 */

// @lc code=start
class Solution {
public:
    static bool compare(const vector<int> v1, const vector<int> v2) {
        if(v1[0] == v2[0])
            return v1[1] < v2[1];
        return v1[0] > v2[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        sort(people.begin(), people.end(), compare);

        for(auto person : people)
            res.insert(res.begin() + person[1], person);

        return res;
    }
};
// @lc code=end

