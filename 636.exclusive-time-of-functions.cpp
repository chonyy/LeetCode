/*
 * @lc app=leetcode id=636 lang=cpp
 *
 * [636] Exclusive Time of Functions
 */

// @lc code=start
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        int prev;
        stack<int> stk;
        for(string log : logs) {
            stringstream ss(log);
            string temp1, action, temp2;
            getline(ss, temp1, ':');
            getline(ss, action, ':');
            getline(ss, temp2, ':');

            int fid = stoi(temp1);
            int cur = stoi(temp2);

            if(action == "start") {
                if(!stk.empty()) {
                    res[stk.top()] += cur - prev;
                }
                stk.push(fid);
                prev = cur;
            }
            else {
                res[stk.top()] += cur - prev + 1;
                stk.pop();
                prev = cur + 1;
            }
        }

        return res;
    }
};
// @lc code=end

