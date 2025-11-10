"""
Double linked list

"""

class Node:

    def __init__(self, data, next = None,back = None):

        self.data = data
        self.next = next
        self.back = back



if __name__ == "__main__":

    head = Node(12)
    node1 = Node(23)
    node2 = Node(13)

    head.next = node1
    head.before = node2

    node3 = Node(14, node2)

    # print(head.data)
    # print(head.next.data)
    # print(head.back)
    # print(head.back.data)


    print(node3.next.data)

