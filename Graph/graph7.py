"""
    Detect the cycle in the Graph
"""


class Graph:

    def __init__(self, vertices):
        self.vertices = vertices
        self.adjList = [[0 for _ in range(vertices)] for _ in range(vertices)]

    def addEdge(self, u, v):
        self.adjList[u][v] = 1
        self.adjList[v][u] = 1


class Solution:

    def detectCycle(self, graph):

        q = []
        vis = [0] * graph.vertices
        parent = [-1] * graph.vertices


        q.append(0)
        vis[0] = 1
        while q:
            node = q.pop(0)

            for neighbour in graph.adjList[node]:

                if not vis[neighbour]:
                    q.append(neighbour)
                    parent[neighbour] = node
                    vis[neighbour] = True

                elif parent[node] != neighbour:
                    return True 
        return False




if __name__ == "__main__":
    g = Graph(4)

    g.addEdge(0, 1)
    g.addEdge(1, 2)
    # g.addEdge(2, 0)
    g.addEdge(3, 1)

    sol = Solution()
    print(sol.detectCycle(g))

    
      