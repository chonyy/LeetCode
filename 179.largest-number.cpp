/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
class Solution {
public:
    static bool compareFnc(string &s1, string &s2) {
        return s1+s2 > s2+s1;
    }

    string largestNumber(vector<int>& nums) {
        string s = "";
        vector<string> arr;

        for(int num : nums) {
            arr.push_back(to_string(num));
        }

        sort(arr.begin(), arr.end(), compareFnc);

        for(string str : arr) {
            s += str;
        }

        while(s[0] == '0' && s.length()>1)
            s.erase(0, 1);

        return s;
    }

};
// @lc code=end

