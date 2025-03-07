from typing import List

class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        boxes = [set() for _ in range(9)]
        empty_cells = []
        
        # Preprocess board and store existing numbers
        for r in range(9):
            for c in range(9):
                if board[r][c] == '.':
                    empty_cells.append((r, c))  # Track empty positions
                else:
                    num = board[r][c]
                    rows[r].add(num)
                    cols[c].add(num)
                    boxes[(r // 3) * 3 + (c // 3)].add(num)

        def solve(index):
            if index == len(empty_cells):  # All cells filled, solution found
                return True
            
            row, col = empty_cells[index]
            box_index = (row // 3) * 3 + (col // 3)

            for num in map(str, range(1, 10)):  # Try numbers '1' to '9'
                if num not in rows[row] and num not in cols[col] and num not in boxes[box_index]:
                    # Place number
                    board[row][col] = num
                    rows[row].add(num)
                    cols[col].add(num)
                    boxes[box_index].add(num)

                    if solve(index + 1):  # Move to next empty cell
                        return True  # Stop when solution found
                    
                    # Backtrack
                    board[row][col] = '.'
                    rows[row].remove(num)
                    cols[col].remove(num)
                    boxes[box_index].remove(num)
            
            return False  # No valid number found
        
        solve(0)
