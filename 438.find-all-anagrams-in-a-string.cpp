/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pMap(26, 0);
        vector<int> sMap(26, 0);
        vector<int> res;
        for(char c : p)
            pMap[c - 'a'] ++;

        int pLen = p.size();
        int i = 0, j = 0;
        while(j < s.size()) {
            if(j - i >= pLen ) {
                sMap[s[i] - 'a'] --;
                i ++;
            }
            sMap[s[j] - 'a'] ++;

            if(sMap == pMap)
                res.push_back(i);

            j ++;
        }

        return res;
    }
};
// @lc code=end

