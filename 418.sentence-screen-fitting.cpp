/*
 * @lc app=leetcode id=418 lang=cpp
 *
 * [418] Sentence Screen Fitting
 */

// @lc code=start
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string joined = "";
        for(string word : sentence) {
            joined += word + ' ';
        }

        int start = 0;
        int n = joined.size();
        for(int i = 0; i < rows; i ++) {
            start += cols;
            while(start > 0 && joined[start % n] != ' ')
                start --;
            start ++;
        }

        return start / n;
    }
};
// @lc code=end

