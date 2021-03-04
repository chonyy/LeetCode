/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

// @lc code=start
class Solution {
public:
    int compress(vector<char>& chars) {
        int idx = 0;
        int i = 0;
        int j = 0;
        int n = chars.size();

        while(i < n) {
            while(j < n && chars[i] == chars[j])
                j ++;

            string num = to_string(j - i);
            char letter = chars[i];

            cout << letter << endl;
            cout << num << endl;
            chars[idx++] = letter;
            if(j - i > 1) {
                for(char c : num) {
                    chars[idx++] = c;
                }
            }

            i = j;
        }
        

        return idx;
    }
};
// @lc code=end

