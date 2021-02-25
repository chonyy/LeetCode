/*
 * @lc app=leetcode id=1138 lang=cpp
 *
 * [1138] Alphabet Board Path
 */

// @lc code=start
class Solution {
public:
    string alphabetBoardPath(string target) {
        string res = "";
        int x = 0, y = 0;
        for(char c : target) {
            int charNum = c - 'a';
            int x1 = charNum % 5;
            int y1 = charNum / 5;
            res += string(max(0, y - y1), 'U')  + string(max(0, x1 - x), 'R') + string(max(0, x - x1), 'L') + string(max(0, y1 - y), 'D');
            res += '!';
            x = x1;
            y = y1;
        }
        return res;
    }
};
// @lc code=end

