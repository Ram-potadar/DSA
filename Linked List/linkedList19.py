
"""
    24. Swap Nodes in Pairs
"""
class Node():
    def __init__(self, val =0 , next = None):
        self.val = val
        self.next = next


class Solution():

    def swap(self, head):
        
        if not head or not head.next:
            return head
        
        newHead = head.next
        curr = head
        dummy = Node()
        dummy.next = head
        prev = dummy
        while curr and curr.next:

            temp = curr.next 
            curr.next = curr.next.next
            temp.next = curr
            prev.next = temp
            prev = curr
            curr = curr.next

        return newHead
    

head = Node(1)
node2 = Node(2)
node3 = Node(3)
node4 = Node(4)
node3.next = node4
node2.next = node3
head.next = node2

sol = Solution()

node = sol.swap(head)

print(node.val)
print(node.next.val)
print(node.next.next.val)
print(node.next.next.next.val)

