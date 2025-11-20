"""
Add 2 numbers in LL
"""

class Node:
    def __init__(self, val , next = None):

        self.val = val
        self.next = next

class Solution:

    def addTwoNumbers(self, head1, head2):

        temp1 = head1
        temp2 = head2
        new_head = Node(-1)
        dummy = new_head
        carry = 0

        while temp1 or temp2:

            sum = 0 
            if temp1: sum += temp1.val
            if temp2: sum += temp2.val

            sum += carry

            carry = sum // 10

            dummy.next = Node(sum%10)
            dummy = dummy.next
            if temp1: temp1 = temp1.next
            if temp2: temp2 = temp2.next

        return new_head.next




if __name__ == "__main__":
    node1 = Node(2)
    node2 = Node(3)
    node3 = Node(4)
    node1.next = node2
    node2.next = node3

    node4 = Node(4)
    node5 = Node(5)
    node4.next = node5
    sol = Solution()

    head = sol.addTwoNumbers(node1, node4)
    print(head.next.next.val)
