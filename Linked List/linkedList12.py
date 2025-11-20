"""
   19. Remove Nth Node From End of List 
"""

class Node:
    def __init__(self, val , next = None):

        self.val = val
        self.next = next

class Solution:

    def reverseBetween(self, head, n):

        fast = head
        slow = head

        for _ in range(n):
            fast = fast.next


        if fast is None:
            return head.next

        while fast.next:

            fast = fast.next
            slow = slow.next

        slow.next = slow.next.next
        return head

if __name__ == "__main__":

    head = Node(1)

    node1 = Node(2)
    head.next = node1

    node2 = Node(3)
    node1.next = node2


    sol = Solution()

    head = sol.removeFromLast(head, 2)

    print(head.next.val)
        

        