/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        if(haystack == "") return -1;

        for(int i = 0; i <= (int)haystack.size() - (int)needle.size(); i ++) {
            cout << i << endl;
            int j = 0;
            for(; j < needle.size(); j ++) {
                if(haystack[i + j] != needle[j])
                    break;
            }
            if(j == needle.size())
                return i;
        }
        return -1;
    }
};
// @lc code=end

