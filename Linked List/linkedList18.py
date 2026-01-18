"""
Detect Loop in LL
"""


class Node():
    def __init__(self, val , next = None):
        self.val = val
        self.next = next

class Solution():

    def detectLoop(self, head):

        fast = head
        slow = head

        while fast and fast.next:

            slow = slow.next
            fast = fast.next.next

            if slow == fast:
                return True
            
        return False
    

    
head1 = Node(1)
head1.next = Node(2)
head1.next.next = Node(3)
head1.next.next.next = Node(4)

sol = Solution()
print("Test 1 (No Loop):", sol.detectLoop(head1))  
# Expected Output: False


# -----------------------------
# TEST 2: Linked List WITH Loop
# -----------------------------
# Creating nodes: 1 -> 2 -> 3 -> 4 -> 5 -> points back to node 3
head2 = Node(1)
head2.next = Node(2)
head2.next.next = Node(3)
head2.next.next.next = Node(4)
head2.next.next.next.next = Node(5)

# Creating the loop: 5 -> 3
head2.next.next.next.next.next = head2.next.next

print("Test 2 (With Loop):", sol.detectLoop(head2))


