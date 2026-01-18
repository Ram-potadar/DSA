"""
    No. of provinces

"""

class Graph:

    def __init__(self, vertices):
        self.vertices = vertices
        self.adjList = {i:[] for i in range(vertices)}
    

    def addEdge(self, u, v):

        self.adjList[u].append(v)
        self.adjList[v].append(u)

class Solution:
    def dfs(self, start, g, vis):
        s = []
        s.append(start)
        vis[start] = 1

        while s:
            vertex = s.pop()
            
            for i in g.adjList[vertex]:
                if not vis[i]:
                    vis[i] = 1
                    s.append(i)
                
    def findProvinces(self, g):

        vis = [0] * g.vertices
        cnt = 0
        for i in range(g.vertices):
            if not vis[i]:
                self.dfs(i, g, vis)
                cnt += 1
        return cnt
    
if __name__ == "__main__":

    g = Graph(6)

    g.addEdge(1, 2)
    g.addEdge(2, 3)
    g.addEdge(4, 5)

    sol = Solution()

    print(sol.findProvinces(g))