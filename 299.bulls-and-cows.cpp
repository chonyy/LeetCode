/*
 * @lc app=leetcode id=299 lang=cpp
 *
 * [299] Bulls and Cows
 */

// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> m;
        int a = 0, b = 0;

        for(int i = 0; i < secret.size(); i ++) {
            char cs = secret[i];
            char cg = guess [i];
            if(cs == cg) {
                a ++;
            }
            else {
                if(m[cs] < 0)
                    b ++;
                if(m[cg] > 0)
                    b ++;

                m[cs] ++;
                m[cg] --;
            }
        }

        return to_string(a) + "A" + to_string(b) + "B";
    }
};
// @lc code=end

