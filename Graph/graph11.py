"""
    Rplave O's with X's
"""


class Solution:

    def replaceOWithX(self, grid):


        n = len(grid)
        m = len(grid[0])

        vis = [[0 for _ in range(m)] for _ in range(n)]
        for row in range(n):
            for col in range(m):
                if (row == 0 or row == n-1 or col == 0 or col == m-1) and grid[row][col] == 'O':
                    self.dfs(row, col, vis, grid)

        for row in range(n):
            for col in range(m):

                if not vis[row][col] and grid[row][col] == 'O':
                    grid[row][col] = 'X'

        return grid

    def dfs(self, row, col, vis, grid):

        vis[row][col] = 1
        n = len(grid)
        m = len(grid[0])
        for direction in [(-1, 0), (1, 0), (0, 1), (0, -1)]:
            nrow = direction[0] + row
            ncol = direction[1] + col
            if nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and grid[nrow][ncol] == 'O':
                self.dfs(nrow, ncol, vis, grid)

if __name__ == "__main__":

    grid = [
        ['X','X','X','X'],
        ['X','O','O','X'],
        ['X','X','O','X'],
        ['X','O','X','X']
    ]

    obj = Solution()
    result = obj.replaceOWithX(grid)

    for row in result:
        print(row)