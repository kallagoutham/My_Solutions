class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(),n = grid[0].size();
        int total = m * n;
        k %= total;
        vector<vector<int>> res(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int t = i * n + j;
                int idx = (t + k) % total;
                int nr = idx / n;
                int nc = idx % n;
                res[nr][nc] = grid[i][j];
            }
        }

        return res;
    }
};
