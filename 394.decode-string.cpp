/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return solve(s, i);
    }

    string solve(string& s, int& i) {
        string res = "";

        while(i < s.size() && s[i] != ']')  {
            if(!isdigit(s[i])) {
                res += s[i];
                i ++;
            }
            else {
                int num = 0;
                while(i < s.size() && isdigit(s[i])) {
                    num = num * 10 + s[i] - '0';   
                    i ++;
                }
                i ++;
                string temp = solve(s, i);
                i ++;

                while(num -- > 0) {
                    res += temp;
                }
            }
        }

        return res;
    }
};
// @lc code=end
