class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m = len(matrix)
        n = len(matrix[0])
        rows = {}
        cols = {}

        for x in range(m):
            for y in range(n):
                if matrix[x][y] == 0:
                    if x not in rows:
                        rows[x] = 1
                    if y not in cols:
                        cols[y] = 1

        for row in rows:
            self.nullify_row(matrix, row)

        for col in cols:
            self.nullify_col(matrix, col)


    def nullify_row(self, matrix, row):
        for i in range(len(matrix[0])):
            matrix[row][i] = 0


    def nullify_col(self, matrix, col):
        for i in range(len(matrix)):
            matrix[i][col] = 0
