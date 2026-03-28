class Solution {
public:
    int numRows,numCols;
    void BFS(vector<vector<char>>& board, int row, int col) {
        queue<pair<int, int>> q;
        q.push(make_pair(row, col));
        while (q.size() > 0) {
            auto front = q.front();
            int row = front.first, col = front.second;
            q.pop();
            if (board[row][col] != 'O') continue;
            board[row][col] = 'E';
            if (col < numCols - 1) q.push(make_pair(row, col + 1));
            if (row < numRows - 1) q.push(make_pair(row + 1, col));
            if (col > 0) q.push(make_pair(row, col - 1));
            if (row > 0) q.push(make_pair(row - 1, col));
        }
    }

    void solve(vector<vector<char>>& board) {
        numRows = board.size();
        if (numRows == 0) return;
        numCols = board[0].size();
        vector<pair<int, int>> border;
        for (int r = 0; r < numRows; ++r) {
            border.push_back(make_pair(r, 0));
            border.push_back(make_pair(r, numCols - 1));
        }
        for (int c = 0; c < numCols; ++c) {
            border.push_back(make_pair(0, c));
            border.push_back(make_pair(numRows - 1, c));
        }
        for (pair<int, int> border_pair : border)
            BFS(board, border_pair.first, border_pair.second);
        for (int r = 0; r < numRows; ++r) {
            for (int c = 0; c < numCols; ++c) {
                if (board[r][c] == 'O') board[r][c] = 'X';
                if (board[r][c] == 'E') board[r][c] = 'O';
            }
        }
    }
};
