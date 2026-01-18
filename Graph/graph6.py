"""
    No of islands
"""


class Solution:

    def bfs(self, row, col, vis, grid):

        q = []
        q.append((row,col))
        n = len(grid)
        m = len(grid[0])
        directions = [(-1,0), (1,0), (0,-1), (0,1), (-1,-1), (-1, 1), (1, -1), (1, 1)]
        while q:
            r, c = q.pop(0)

            for dr, dc in directions:
                nr = r + dr
                nc = c + dc

                if (0 <= nr < n and 0 <= nc < m and
                    not vis[nr][nc] and grid[nr][nc] == '1'):
                    
                    vis[nr][nc] = 1
                    q.append((nr, nc))
                        
        
    def numIslands(self, grid):

        n = len(grid)
        m = len(grid[0])
        vis = [[0 for _ in range(m)] for _ in range(n)]
        cnt = 0
        for row in range(n):
            for col in range(m):
                if not vis[row][col] and grid[row][col] == '1':
                    vis[row][col] = 1
                    self.bfs(row, col, vis, grid)
                    cnt += 1
               

        return cnt
    
if __name__ == "__main__":
        grid = [
            ["1","1","0","0","0"],
            ["1","1","0","0","0"],
            ["0","0","1","0","0"],
            ["0","0","0","1","1"]
        ]

        sol = Solution()
        print("Number of Islands:", sol.numIslands(grid))
