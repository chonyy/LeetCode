class Solution {
public:
    int rows;
    int cols;
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        rows = maze.size();
        cols = maze[0].size();
        
        int startRow = start[0];
        int startCol = start[1];
        int endRow = destination[0];
        int endCol = destination[1];
        unordered_set<int> visited;
        
        return walk(maze, startRow, startCol, endRow, endCol, visited);
    }
    
    bool walk(vector<vector<int>>& maze, int curRow, int curCol, int endRow, int endCol, unordered_set<int>& visited) {
        int loc = curRow * cols + curCol;
        cout << curRow << " " << curCol << endl;
        
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
            visited.insert(loc);
            if(walk(maze, newRow, newCol, endRow, endCol, visited))
                return true;
            visited.erase(loc);
        }

        return false;
    }
};