/*
 * @lc app=leetcode id=1005 lang=cpp
 *
 * [1005] Maximize Sum Of Array After K Negations
 */

// @lc code=start
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        int bucket[201] = {0};

        for(int a : A) {
            bucket[a+100] ++;
        }

        for(int i = -100; i <= 100; i ++) {
            if(bucket[i+100]) {
                if(i >= 0) {
                    if(K % 2) {
                        bucket[i+100] --;
                        bucket[-i+100] ++;
                    }
                    break;
                }

                int toMinus = min(bucket[i+100], K);
                bucket[i+100] -= toMinus;
                bucket[-i+100] += toMinus;
                K -= toMinus;
            }
        }

        int sum = 0;
        for(int i = -100; i <= 100; i ++) {
            if(bucket[i+100])
                sum += i * bucket[i+100];
        }

        return sum;
    }
};
// @lc code=end

