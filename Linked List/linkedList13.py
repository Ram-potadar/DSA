"""
        206. Reverse Linked List
"""


class Node:
    def __init__(self, val , next = None):

        self.val = val
        self.next = next

class Solution:


        def reverseList(self, head):
             
             prev = None
             curr = head
             if  not head or head.next == None:
                  return head
             while curr:
                temp = curr.next
                curr.next = prev
                prev = curr
                curr = temp
             
             return prev


if __name__ == "__main__":
     
    head = Node(1)

    node1 = Node(2)
    head.next = node1

    node2 = Node(3)
    node1.next = node2


    sol = Solution()

    head = sol.reverseList(head)

    print(head.val)