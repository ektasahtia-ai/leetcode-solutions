class Solution:
    def solveNQueens(self, n):
        
        def backtrack(row):
            if row == n:
                result.append(["".join(r) for r in board])
                return
            
            for col in range(n):
                
                if col in cols or (row - col) in diagonals or (row + col) in anti_diagonals:
                    continue
                
                # Place Queen
                board[row][col] = 'Q'
                cols.add(col)
                diagonals.add(row - col)
                anti_diagonals.add(row + col)
                
                # Next row
                backtrack(row + 1)
                
                # Remove Queen (Backtrack)
                board[row][col] = '.'
                cols.remove(col)
                diagonals.remove(row - col)
                anti_diagonals.remove(row + col)
        
        result = []
        board = [['.'] * n for _ in range(n)]
        
        cols = set()
        diagonals = set()
        anti_diagonals = set()
        
        backtrack(0)
        
        return result