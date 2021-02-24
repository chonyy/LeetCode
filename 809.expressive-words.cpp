/*
 * @lc app=leetcode id=809 lang=cpp
 *
 * [809] Expressive Words
 */

// @lc code=start
class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int sum = 0;
        for(string word : words) {
            if(check(S, word))
                sum ++;
        }
        return sum;
    }

    bool check(string s, string word) {
        int i = 0, j = 0;
        int i2 = 0, j2 = 0;
        int n = s.size();
        int m = word.size();
        while(i2 < n) {
            i = i2;
            j = j2;
            if(s[i] != word[j]) {
                return false;

            }
            while(i2 < n && s[i2] == s[i]) {
                i2 ++;
            }
            while(j2 < m && word[j2] == word[j]){
                j2 ++;
            }
            if(i2-i != j2-j && i2 - i < max(3, j2 - j))
                return false;
        }
        return i2 == n && j2 == m;
    }
};
// @lc code=end

