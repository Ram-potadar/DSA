"""
Rotting oranges
"""


class Solution:

    def orangesRotting(self, grid):
        n = len(grid)
        m = len(grid[0])
        q = []
        maxTime = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 2:
                    q.append((i, j, 0))


        
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        while q:
            row, col, time= q.pop(0)

            maxTime = max(time, maxTime)

            for r, c in directions:

                nr = row + r
                nc = col + c
                if nr >= 0 and nr < n and nc >= 0 and nc < m and grid[nr][nc] == 1:
                    grid[nr][nc] = 2
                    q.append((nr, nc, time + 1))

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    return -1

        return maxTime

            
if __name__ == "__main__":
    grid = [
        [2, 1, 1],
        [1, 1, 0],
        [0, 1, 1]
    ]

    sol = Solution()
    result = sol.orangesRotting(grid)
    print("Minimum time:", result)