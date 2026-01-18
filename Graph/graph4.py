"""
    Graph Traversal -> DFS (Deapth first Search)

    Time Complexity = O(N)
    Space Complexity = O(N)
    
"""
class Graph:

    def __init__(self, vertices):

        self.vertices = vertices
        self.adj = {i:[] for i in range(vertices)}


    def add_edge(self, u, v):

        self.adj[u].append(v)
        self.adj[v].append(u)

class Solution:

    def dfsTravesal(self, start, g):
       
        s = []
        vis = [0] * g.vertices
        s.append(start)
        vis[start] = 1

        while s:
            vertex = s.pop()
            print(vertex, end = " ")
            for i in g.adj[vertex]:
                if not vis[i]:
                    vis[i] = 1
                    s.append(i)
            

if __name__== "__main__":

    g = Graph(7)

    g.add_edge(1, 2)
    g.add_edge(6, 2)
    g.add_edge(1, 3)
    g.add_edge(4, 3)
    g.add_edge(5, 3)


    sol = Solution()
    sol.dfsTravesal(1, g)

