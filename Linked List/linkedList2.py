"""
    Convert Array to Linked List, Traversal, and length of LL
"""


class Node:
    def __init__(self, data, next = None):

        self.data = data
        self.next = next



def convertArraytoLinkedList(nums):

    head = Node(nums[0])
    current = head

    for item in nums[1:]:
        current.next = Node(item)
        current = current.next


    return head

def display(head):
    current = head
    while current:
        print(current.data, end=" -> ")
        current = current.next

    print("None")


def lengthofLL(head):
    cnt = 0
    current = head
    while current:
        cnt += 1
        current = current.next

    return cnt

def checkTarget(head, target):
    current = head
    while current:
        if target == current.data:
            return True
        current = current.next

    return False




if __name__ == "__main__":

    arr = [2,3,4,5,6]

    head = convertArraytoLinkedList(arr) #O(N)

    display(head) #O(N)

    print("length of LL ", lengthofLL(head)) # O(N)

    print(checkTarget(head, 4))   # O(N)


