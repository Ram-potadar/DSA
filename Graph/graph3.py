"""
    BFS traversal of Graph
"""


class Graph:

    def __init__(self, vertices):

        self.vertices = vertices
        self.adj = {i:[] for i in range(vertices)}


    def add_edge(self, u, v):

        self.adj[u].append(v)
        self.adj[v].append(u)

class Solution:

    def bfsTravesal(self, start, g):
        q = []
        vis = [0] * g.vertices
        q.append(start)
        vis[start] = 1

        while  q:
            node = q.pop(0)
            for i in g.adj[node]:
                if not vis[i]:
                    vis[i] = 1
                    q.append(i)
            print(node, end=" ")

if __name__== "__main__":

    g = Graph(7)

    g.add_edge(1, 2)
    g.add_edge(6, 2)
    g.add_edge(1, 3)
    g.add_edge(4, 3)
    g.add_edge(5, 3)


    sol = Solution()
    sol.bfsTravesal(1, g)
