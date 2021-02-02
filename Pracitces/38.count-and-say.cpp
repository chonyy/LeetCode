/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        if(n == 0) return "";

        string ans = "1";

        for(int i = 1; i < n ; i ++) {
            string temp = "";
            int m = ans.size();
            for(int j = 0; j < m; j ++) {
                cout << "Calculating " << j << endl;
                int count = 1;
                while(j + 1 < m && ans[j] == ans[j+1]) {
                    cout << count << endl;
                    count ++;
                    j ++;
                }
                temp += to_string(count) + ans[j]; 
            }
            ans = temp;
            cout << ans << endl;
        }

        return ans;
    }
};
// @lc code=end

