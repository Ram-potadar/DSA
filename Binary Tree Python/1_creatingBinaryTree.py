
class Node: #Define a node class for the binary tree
    def __init__(self, val):

        self.data = val
        self.left= None
        self.right = None


if __name__== "__main__":

    root = Node(1) # Create root Node with value 1
    root.left = Node(8)
    root.right = Node(23)
    root.left.left = Node(2)
    root.left.right = Node(21)


    print("Data at root node: ", root.data)
    print("Data at left node: ", root.left.data)
    print("Data at right node: ", root.right.data)

