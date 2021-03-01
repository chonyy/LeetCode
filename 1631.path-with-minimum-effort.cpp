class Solution {
public:
    int rows;
    int cols;
    vector<vector<int>> h;
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        h = heights;
        rows = heights.size();
        cols = heights[0].size();

        int start = 0, end = 1000000;
        int ans = INT_MAX;
        while(start <= end) {
            vector<vector<bool>> visited(100, vector<bool>(100, false));
            int mid = start + (end - start) /2 ;
            cout << mid << endl;
            if(dfs(0, 0, mid, visited)) {
                end = mid - 1;
                ans = min(ans, mid);
            }
            else {
                start = mid + 1;
            }
        }

        return ans;
    }

    bool dfs(int i, int j, int threshold, vector<vector<bool>>& visited) {
        if(i == rows-1 && j == cols-1)
            return true;

        visited[i][j] = true;
        bool success = false;
        for(int k = 0; k < 4; k ++) {
            int x = i + dirs[k][0];
            int y = j + dirs[k][1];
            if(x < 0 || x >= rows || y < 0 || y >= cols) 
                continue;
            if(visited[x][y])
                continue;

            int diff = abs(h[x][y] - h[i][j]);
            if(diff <= threshold) {
                success = success | dfs(x, y, threshold, visited);
            }
        }

        return success;
    }
};
// @lc code=end

