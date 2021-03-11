/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 */

// @lc code=start
class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> count;
        int n = S.size();
        char mostFreq = S[0];

        for(char c : S) {
            count[c] ++;
            if(count[c] > count[mostFreq])
                mostFreq = c;
        }

        cout << mostFreq << count[mostFreq] << endl;
        cout << n+1/2 << endl;
        if(count[mostFreq] > (n+1)/2)
            return "";

        int idx = 0;
        while(count[mostFreq] > 0) {
            S[idx] = mostFreq;
            count[mostFreq] --;
            idx += 2;
        }

        for(auto it = count.begin(); it != count.end(); it ++) {
            while(it->second) {
                if(idx >= n)
                    idx = 1;
                S[idx] = it->first;
                it->second --;

                idx += 2;
            }
        }

        return S;
    }
};
// @lc code=end

