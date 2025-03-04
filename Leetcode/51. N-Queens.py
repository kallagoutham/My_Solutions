class Solution:
    def __init__(self):
        self.res = []

    def check(self, rowIdx, colIdx, board, n):
        for i in range(colIdx):
            if board[rowIdx][i] == 1:
                return False

        i, j = rowIdx, colIdx
        while i >= 0 and j >= 0:
            if board[i][j] == 1:
                return False
            i -= 1
            j -= 1

        i, j = rowIdx, colIdx
        while i < n and j >= 0:
            if board[i][j] == 1:
                return False
            i += 1
            j -= 1

        return True

    def transform(self, temp, n):
        tempans = []
        for i in temp:
            tempans.append("." * i + "Q" + "." * (n - i - 1))
        return tempans

    def backtrack(self, colIdx, board, temp, n):
        if colIdx == n:
            self.res.append(self.transform(temp, n))
            return
        
        for rowIdx in range(n):
            if self.check(rowIdx, colIdx, board, n):
                board[rowIdx][colIdx] = 1  
                temp.append(rowIdx)  
                self.backtrack(colIdx + 1, board, temp, n)  
                temp.pop()  
                board[rowIdx][colIdx] = 0  

    def solveNQueens(self, n: int):
        board = [[0] * n for i in range(n)] 
        self.backtrack(0, board, [], n) 
        return self.res
