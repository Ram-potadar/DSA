

class Node:

    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next


class Solution(object):
    def reverse(self, head):
        temp = head
        prev = None
        while temp:
            nextNode = temp.next
            temp.next = prev
            prev = temp
            temp = nextNode

        return prev

    def reverseBetween(self, head, left, right):
        """
        :type head: Optional[ListNode]
        :type left: int
        :type right: int
        :rtype: Optional[ListNode]
        """
        if not head or not head.next:
            return head
        temp = head
        rightNext = leftNode = rightNode = None
        while temp:
            print("Temp val : ", temp.val)
            if right == temp.val:
                rightNode = temp
                print("found r")
            if left == temp.val:
                print("found l")
                leftNode = temp
            temp = temp.next
        if leftNode and rightNode:
            print("left: ", leftNode.val)
            print("right: ", rightNode.val)
        if rightNode:
            rightNext = rightNode.next
            rightNode.next = None
        head.next = self.reverse(leftNode)
        leftNode.next = rightNext
        return head



if __name__ == "__main__":

    head = Node(1)
    head.next = Node(2)
    head.next.next = Node(3)
    head.next.next.next = Node(4)
    head.next.next.next.next = Node(5)


    sol = Solution()
    sol.reverseBetween(head, 2, 4)
    print(head.next.val)

        