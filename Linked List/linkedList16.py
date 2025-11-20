"""
    Add 1 to the linked list
"""

class Node:
    def __init__(self, val, next = None):
        self.val = val
        self.next = next


class Solution:

    def helper(self, temp):
        if not temp:
            return 1
        carry = self.helper(temp.next)

        temp.val = temp.val + carry 

        if temp.val < 10:
            return 0
        temp.val = 0
        return 1
    

    def addOneToList(self, head):
        carry = self.helper(head)
        if carry:
            newHead = Node(carry, head)
            return newHead

        return head
    

    
    
if __name__ == "__main__":

    head = Node(9)

    node1 = Node(9)
    head.next = node1

    node2 = Node(9)
    node1.next = node2

    sol = Solution()

    head = sol.addOneToList(head)

    print(head.next.next.next.val)

