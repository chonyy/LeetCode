/*
 * @lc app=leetcode id=340 lang=cpp
 *
 * [340] Longest Substring with At Most K Distinct Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int start = 0;
        int end = 0;
        int n = s.size();
        int res = 0;
        unordered_map<char, int> m;

        while(end < n && start <= end) {
            m[s[end]] ++;

            while(m.size() > k) {
                cout << start << endl;
                cout << s[start] << " " << s[end] << endl;

                m[s[start]] --;
                if(m[s[start]] == 0)
                    m.erase(s[start]);
                cout << m.size() << endl;
                start ++;
            }

            cout << "record" << endl;
            cout << end << start << endl;
            res = max(res, end - start + 1);
            end ++;
        }

        return res;
    }
};
// @lc code=end

