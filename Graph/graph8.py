"""
    Colouring the graph
"""


class Solution:

    def colorImg(self, image, sr, sc, newColor):

        ans = image

        initialColor = image[sr][sc]


        self.dfs(sr, sc, image, ans, newColor, initialColor)

        return ans

    def dfs(self, row , col, image, ans, newColor, initialColor):
        
        n = len(image)
        m = len(image[0])
        ans[row][col] = newColor     
        directions = [(0, -1), (0, 1), (-1, 0), (1, 0)]


        for r, c in directions:

            nr = row + r
            nc = col + c
            if nr >= 0 and nr < n and nc >= 0 and nc < m and image[nr][nc] == initialColor  and ans[nr][nc] != newColor:

                self.dfs(nr, nc, image, ans, newColor, initialColor)




if __name__ == "__main__":
    image = [
        [1, 1, 1],
        [1, 1, 0],
        [1, 0, 1]
    ]

    sr = 1   # start row
    sc = 1   # start col
    newColor = 2

    sol = Solution()
    result = sol.colorImg(image, sr, sc, newColor)

    print("Colored Image:")
    for row in result:
        print(row)


