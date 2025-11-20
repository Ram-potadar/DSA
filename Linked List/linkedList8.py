"""
    Reverse Double Linked List
"""


class Node:
    def __init__ (self, data, next = None, back = None):
        self.data = data
        self.next = next
        self.back = back

class Solution:

    def reverseDLL(self, head):

        if not head:
            return None

        current = head
        prev = None

        while current:
            current.back, current.next = current.next, current.back
            prev = current
            current = current.back  
        return prev
    

if __name__ == "__main__":
    head = Node(1)

    node1 = Node(2, None, head)
    head.next = node1

    node2 = Node(3, None, node1)
    node1.next = node2

    obj = Solution()

    head = obj.reverseDLL(head)
    if head:
        print(head.data)


