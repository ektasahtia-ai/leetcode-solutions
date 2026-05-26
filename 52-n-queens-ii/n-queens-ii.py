class Solution:
    def totalNQueens(self, n):

        def backtrack(row):
            if row == n:
                return 1

            count = 0

            for col in range(n):

                if col in cols or (row - col) in diagonals or (row + col) in anti_diagonals:
                    continue

                # Place queen
                cols.add(col)
                diagonals.add(row - col)
                anti_diagonals.add(row + col)

                # Move to next row
                count += backtrack(row + 1)

                # Backtrack
                cols.remove(col)
                diagonals.remove(row - col)
                anti_diagonals.remove(row + col)

            return count

        cols = set()
        diagonals = set()
        anti_diagonals = set()

        return backtrack(0)