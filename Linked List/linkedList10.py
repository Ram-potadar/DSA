"""
    328. Odd Even Linked List
"""

class Node:
    def __init__(self, val , next = None):

        self.val = val
        self.next = next

class Solution:

    def oddEvenList(self, head):

        even = head.next
        evenHead = head.next
        odd = head

        while even.next and even.next.next:
            odd.next = odd.next.next
            even.next = even.next.next

            odd = odd.next
            even = even.next
        odd.next = evenHead
        
        return head
    


if __name__ == "__main__":

    head = Node(1)

    node1 = Node(2)
    head.next = node1

    node2 = Node(3)
    node1.next = node2

    node3 = Node(4)
    node2.next = node3

    node4 = Node(5)
    node3.next = node4


    node5 = Node(6)
    node4.next = node5

    node6 = Node(7)
    node5.next = node6



    obj = Solution()

    head = obj.oddEvenList(head)

    print(head.next.val)

    
    
