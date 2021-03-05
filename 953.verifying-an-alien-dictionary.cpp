/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 */

// @lc code=start
class Solution {
public:
    unordered_map<char, int> m;
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();

        for(int i = 0; i < 26; i ++) {
            m[order[i]] = i;
        }

        for(int i = 1; i < n; i ++) {
            if(compare(words[i-1], words[i]) > 0)
                return false;
        }

        return true;
    }

    int compare(string word1, string word2) {
        int cmp = 0;
        int i = 0;
        int j = 0;

        while(i < word1.size() && j < word2.size() && cmp == 0) {
            cmp = m[word1[i]] - m[word2[j]];
            i ++;
            j ++;
        }

        if(cmp == 0)
            return word1.size() - word2.size();

        return cmp;
    }
};
// @lc code=end

