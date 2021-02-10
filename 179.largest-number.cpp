/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
class Solution {
public:
    static bool compareFnc(string s1, string s2) {
        return s1 + s2 > s2 + s1;
    }

    string largestNumber(vector<int>& nums) {
        string res = "";
        vector<string> temp;

        for(int i : nums)
            temp.push_back(to_string(i));

        sort(temp.begin(), temp.end(), compareFnc);

        for(string s : temp) 
            res += s;

        while(res[0] == '0' && res.length()>1)
            res.erase(0, 1);

        return res;
    }
};
// @lc code=end

