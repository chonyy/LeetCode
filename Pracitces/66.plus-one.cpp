/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 0;

        digits[n-1] += 1;

        while(n --) {
            digits[n] += carry;
            if(digits[n] >= 10) {
                cout << "large" << endl;
                digits[n] -= 10;
                carry = 1;
            }
            else 
                carry = 0;
        }

        if(carry) {
            cout << "inset" << endl;
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};
// @lc code=end

