"""
    234. Palindrome Linked List
"""

class Node:
    def __init__(self, val, next = None):
        self.val = val
        self.next = next


class Solution:

    def reverse(self, head):
             
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

    def isPalindrome(self, head):


        if not head or head.next == None:
            return head
        
        slow = head 
        fast = head


        while fast.next and fast.next.next:

            slow = slow.next
            fast = fast.next.next

        newHead = self.reverse(slow.next)

        first = head
        second = newHead
        while second:
            if first.val != second.val:
                return False
            
            first = first.next
            second = second.nextko


        self.reverse(newHead)

        return True
    
if __name__ == "__main__":

    head = Node(1)

    node1 = Node(2)
    head.next = node1

    node2 = Node(3)
    node1.next = node2

    node3 = Node(3)
    node2.next = node3

    node4 = Node(4)
    node3.next = node4

    node5 = Node(1)
    node4.next = node5

    sol = Solution()
    middle = sol.isPalindrome(head)

    print(middle)
        