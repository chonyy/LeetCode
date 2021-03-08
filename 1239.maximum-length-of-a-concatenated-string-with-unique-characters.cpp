/*
 * @lc app=leetcode id=1239 lang=cpp
 *
 * [1239] Maximum Length of a Concatenated String with Unique Characters
 */

// @lc code=start
class Solution {
public:
    int n = 0;
    int curMax = 0;
    int maxLength(vector<string>& arr) {
        n = arr.size();
        string cur = "";
        dfs(arr, 0, cur);
        return curMax;
    }

    void dfs(vector<string>& arr, int idx, string s) {
        cout << idx << s << endl;

        curMax = max(curMax, (int)s.length());
        for(int i = idx; i < n; i ++) {
            cout << "checking " << s << " " << arr[i] << endl;
            if(check(s, arr[i])) {
                dfs(arr, i+1, s + arr[i]);
            }
        }
    }

    bool check(string s1, string s2) {
        vector<int> count(26, 0);

        for(char c : s1) {
            if(count[c - 'a'] > 0)
                return false;
            count[c - 'a'] ++;
        }

        for(char c : s2) {
            if(count[c - 'a'] > 0)
                return false;
            count[c - 'a'] ++;
        }

        return true;
    }
};
// @lc code=end

