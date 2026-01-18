"""
        25. Reverse Nodes in k-Group
"""

class Node:

    def __init__ (self, val = 0, next = None):

        self.val = val
        self.next = next

class Solution:
    def reverse(self, head):

        temp = head
        prev = None
        while temp:
            nextNode = temp.next
            temp.next = prev
            prev = temp
            temp = nextNode

        return prev

    def findKthNode(self, head, k):
        temp = head
        while temp and k - 1 > 0:
            k -= 1
            temp = temp.next
        return temp

    def reverseKGrp(self, head, k):

        prevNode = None
        temp = head

        while temp:

            kthNode = self.findKthNode(temp, k)
            if not kthNode:
                if prevNode : 
                    prevNode.next = temp
                    break
            nextNode = kthNode.next
            kthNode.next = None

            self.reverse(temp)

            if temp == head:
                head = kthNode

            else:
                prevNode.next = kthNode

                
            prevNode = temp
            temp = nextNode

        return head
    

head = Node(1)
node2 = Node(2)
node3 = Node(3)
node4 = Node(4)
node5 = Node(5)
node3.next = node4
node2.next = node3
head.next = node2
node4.next = node5

sol = Solution()

node = sol.reverseKGrp(head, 2)

print(node.val)
print(node.next.val)
print(node.next.next.val)
print(node.next.next.next.val)
print(node.next.next.next.next.val)


            



