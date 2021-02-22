/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

// @lc code=start
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for(int i = 1; i <= n; i ++) {
            string ans;
            if(i % 15 == 0)
                ans = "FizzBuzz";
            else if(i % 3 == 0)
                ans = "Fizz";
            else if(i % 5 == 0)
                ans = "Buzz";
            else
                ans = to_string(i);
            res.push_back(ans);
        }

        return res;
    }
};
// @lc code=end

