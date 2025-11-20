"""
        876. Middle of the Linked List
"""


class Node:
    def __init__(self, val , next = None):

        self.val = val
        self.next = next

class Solution:

    def middleNode(self, head):
        slow = head
        fast = head

        if not head:
            return head
        
        if head.next == None:
            return head.next
        

        while fast and fast.next :
            slow = slow.next
            fast = fast.next.next

        return slow 
    

if __name__ == "__main__":
     
    head = Node(1)

    node1 = Node(2)
    head.next = node1

    node2 = Node(3)
    node1.next = node2


    sol = Solution()

    middle = sol.middleNode(head)

    print(middle.val)

