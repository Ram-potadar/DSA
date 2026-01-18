"""
    Distance of nearest cell having 1
"""

from collections import deque
class Solution:


    def findDist(self, grid):

        q = deque()
        n= len(grid)
        m = len(grid[0])
        vis = [[0 for _ in range(m)] for _ in range(n)]
        distMatrix = [[0 for _ in range(m)] for _ in range(n)]
        for i in range(n):
            for j in range(m):

                if grid[i][j] == 1:

                    q.append((i, j, 0))
                    vis[i][j] = 1

        while q:

            row, col, dist = q.popleft()
            distMatrix[row][col] = dist
            for r, c in [(-1, 0), (1, 0), (0, 1), (0, -1)]:

                nr = row + r
                nc = col + c

                if nr >= 0 and nr < n and nc >= 0 and nc < m and not vis[nr][nc] :
                    vis[nr][nc] = 1
                    q.append((nr, nc, dist+1))

        return distMatrix
    

if __name__ == "__main__":

    grid = [
        [0, 0, 0],
        [0, 1, 0],
        [1, 0, 0]
    ]

    obj = Solution()
    result = obj.findDist(grid)

    print("Distance Matrix:")
    for row in result:
        print(row)





        


                

            

                    
