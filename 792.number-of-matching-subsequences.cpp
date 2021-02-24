/*
 * @lc app=leetcode id=792 lang=cpp
 *
 * [792] Number of Matching Subsequences
 */

// @lc code=start
class Solution {
public:
    unordered_map<char, vector<int>> m;
    unordered_map<string, bool> cache;
    int numMatchingSubseq(string S, vector<string>& words) {
        int sum = 0;

        for(int i = 0; i < S.size(); i ++) {
            m[S[i]].push_back(i);
        }

        for(string word : words) {
            sum += check(S, word);
        }
        return sum;
    }

    bool check(string s, string word) {
        if(cache.count(word))
            return cache[word];
        int cur = -1;
        for(char c : word) {
            auto loc = m[c];
            auto it = lower_bound(loc.begin(), loc.end(), cur+1);
            if(it == loc.end()) {
                cache[word] = false;
                return false;
            }
            cur = *it;
        }
        cache[word] = true;
        return true;
    }
};
// @lc code=end

