# include<bits/stdc++.h>

using namespace std;

int rows;
int cols;
vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool walk(vector<vector<int>>& maze, int curRow, int curCol, int endRow, int endCol, unordered_set<int>& visited, vector<vector<int>>& res) {
    int loc = curRow * cols + curCol;
    
    if(curRow < 0 || curRow >= rows || curCol < 0 || curCol >= cols) {
        return false;
    }

    if(maze[curRow][curCol] == 1)
        return false;
    
    if(visited.find(loc) != visited.end()) {
        return false;
    }
    
    if(curRow == endRow && curCol == endCol) {
        return true;
    }
    
    for(auto dir : dirs) {
        int newRow = curRow + dir[0];
        int newCol = curCol + dir[1];
        res.push_back({newRow, newCol});
        visited.insert(loc);
        if(walk(maze, newRow, newCol, endRow, endCol, visited, res))
            return true;
        visited.erase(loc);
        res.pop_back();
    }

    return false;
}

vector<vector<int>> hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
    vector<vector<int>> res;
    rows = maze.size();
    cols = maze[0].size();
    
    int startRow = start[0];
    int startCol = start[1];
    int endRow = destination[0];
    int endCol = destination[1];
    unordered_set<int> visited;
    
    if(walk(maze, startRow, startCol, endRow, endCol, visited, res))
        return res;
    return {};
}

int main() {
    vector<vector<int>> grid = {{1, 1, 1, 1, 1}, {1, 0, 0, 0, 1}, {1, 0, 0, 0, 1}, {1, 0, 0, 0, 1}, {1, 1, 1, 1, 1}};
    vector<int> start = {3, 1};
    vector<int> end = {1, 1};

    auto res = hasPath(grid, start, end);

    for(auto p : res)
        cout << p[0] << " " << p[1] << endl; 

    return 0; 
}

// 11111
// 10001
// 11101
// 10001
// 11111