class Solution {
public:
    int rows;
    int cols;
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    const int mod = 1e9 + 7;
    
    int solve(int remain, int row, int col, vector<vector<vector<int>>>& dp) {
        if(remain < 0) {
            return 0;
        }
        
        if(col < 0 || col >= cols || row < 0 || row >= rows) {
            return 1;
        }

        if(dp[row][col][remain])
            return dp[row][col][remain];
        
        for(auto dir : dirs) {
            dp[row][col][remain] += solve(remain-1, row+dir[0], col+dir[1], dp) % mod;
            dp[row][col][remain] %= mod;
        }

        return dp[row][col][remain];
    }
    
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(N+1, 0)));
        rows = m;
        cols = n;
        return solve(N, i, j, dp);
    }
};