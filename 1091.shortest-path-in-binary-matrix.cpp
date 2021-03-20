/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 */

// @lc code=start
class Solution {
    int estimate(int row, int col) {
        return max(n - row, n - col);
    }
    int n;
public:
    vector<vector<int>> dirs = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();

        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;
        if(n == 1)
            return 1;

        auto cmp = [](vector<int> v1, vector<int> v2) {return v1[3] > v2[3];};
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q(cmp);
        set<vector<int>> visited;

        // x, y, distance, estimate
        q.push({0, 0, 1, n});

        while(!q.empty()) {
            int x = q.top()[0];
            int y = q.top()[1];
            int distance = q.top()[2];
            int estimate = q.top()[3];
            q.pop();

            // cout << endl;
            // cout << x << " " << y << endl;

            // Check we get the answer
            if(x == n - 1 && y == n - 1)
                return distance;

            // visit this cell
            visited.insert({x, y});

            // for all possible directions
            for(auto dir : dirs) {
                int newX = x + dir[0];
                int newY = y + dir[1];
                // cout << newX << " " << newY << endl;

                if(newX < 0 || newX >= n || newY < 0 || newY >= n) {
                    // cout << "bouc" << endl;
                    continue;
                }

                if(grid[newX][newY] == 1) {
                    // cout << "wall" << endl;
                    continue;
                }

                // skip if visited
                if(visited.find({newX, newY}) != visited.end()) {
                    // cout << "visited" << endl;
                    continue;
                }

                // cout << "push" << distance + 1 << " " << max(n - newX, n - newY) + distance << endl;
                q.push({newX, newY, distance + 1, max(n - newX, n - newY) + distance});
            }
        }

        return -1;
    }

};
// @lc code=end

