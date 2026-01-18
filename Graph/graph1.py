"""
Representation of graph using adjacency matrix

"""

if __name__ == "__main__":

    n = int(input("Enter number of vertices: "))
    m = int(input("Enter number of edges: "))


    adj = [[0 for _ in range(n)] for _ in range(n)]

    for _ in range(m):
        u = int(input("Enter u: "))
        v = int(input("Enter v: "))

        adj[u][v] = 1
        adj[v][u] = 1   

    print("Adjacency Matrix:")
    for row in adj:
        print(row)
