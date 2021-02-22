/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x;
        int mid;

        if(x == 0) return 0;

        while(left <= right) {
            mid = left + (right - left) / 2;
            if(mid == x/mid)
                return mid;
            else if(mid > x/mid)  {
                right = mid - 1;
            }
            else if(mid < x/mid){
                if(mid + 1 > x / (mid+1))
                    return mid;
                left = mid + 1;
            }
        }
        return mid;
    }
};
// @lc code=end

