"""
    Find the lenght and first node of loop in LL

"""


class Node:
    def __init__ (self, val = 0, next = None):

        self.val = val
        self.next = next

class Solution:

    def findFistNode(self, head):

        if not head or not head.next:
            return None
        
        fast = slow = head


        temp = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                slow = head
                while slow != fast:
                    fast = fast.next
                    slow = slow.next
                return slow
            
        return None
    
    def findLength(self, head):

        if not head or not head.next:
            return 0
        
        fast = slow = head


        temp = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                cnt = 2
                slow = slow.next
                while slow != fast:
                    cnt += 1
                    slow = slow.next
                return cnt
            
        return 0
    
head1 = Node(1)
head1.next = Node(2)
head1.next.next = Node(3)
head1.next.next.next = Node(4)

head1.next.next.next  = head1.next
sol = Solution()
print("Lenght of loop is :", sol.findLength(head1))  
print("First node of loop is :", sol.findFistNode(head1).val)  

    


