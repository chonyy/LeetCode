class Solution {
public:
    int dp[10001] = {0};
    int racecar(int target) {
        if(dp[target] > 0)
            return dp[target];
        
        int n = floor(log2(target)) + 1;
        
        // Getting the answer right away, 2^2 == 3 + 1
        if(1 << n == target + 1) {
            dp[target] = n;
            return dp[target];
        }
        else {
            // Go pass the target and turn back
            // answer of turning back + steps to reach here + 1 R
            dp[target] = racecar((1 << n) - 1 - target) + n + 1;
            // Go as far before passing the target, then turn back
            for(int i = 0; i < n - 1; i ++) {
                // cur location = the cur point minus the distance turning back
                int cur = ((1 << (n-1)) - (1 << i));
                dp[target] = min(dp[target], racecar(target-cur) + n + 1 + i);
            }
        }
        return dp[target];
    }
};