#include <vector>

using namespace std;

class Solution {
public:
    void DFS(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') {
            return;
        }
        
        grid[i][j] = '0';
        
        DFS(grid, i + 1, j);
        DFS(grid, i - 1, j);
        DFS(grid, i, j + 1);
        DFS(grid, i, j - 1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int rows = grid.size();
        if (rows == 0) return 0;
        int columns = grid[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (grid[i][j] == '1') {
                    ++res;
                    DFS(grid, i, j);
                }
            }
        }

        return res;
    }
};
