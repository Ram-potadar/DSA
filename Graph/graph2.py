"""
Representing the graph using adjancency list

"""


class Graph:

    def __init__(self, vertices):

        self.vertices = vertices
        self.adj = {i:[] for i in range(vertices)}


    def add_edge(self, u, v):

        self.adj[u].append(v)
        self.adj[v].append(u)

    def printGraph(self):

        for i in self.adj:
            print(f"Neighbors of node {i}", self.adj[i])


if __name__=="__main__":

    g = Graph(3)

    g.add_edge(0,1)
    g.add_edge(1,2)
    g.add_edge(0,2)

    g.printGraph()

    