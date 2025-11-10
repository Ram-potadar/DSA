"""
    Deletion of node  

        -> Head
        -> Tail
        -> Position
        -> Value

    
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
        print(current.data, end=" ")
        current = current.next
    print("None")
    

def deleteHead(head):           # Deleting the head of the LL

    if not head:
        return None
    temp = head
    head = head.next
    del temp
    return head


def deleteTail(head):       # Deleting the tail of the LL

    if not head or head.next == None:
        return None

    current = head 
    while current.next.next is not None:
        current = current.next

    del current.next
    current.next = None
    return head

def deleteKth(head, k):     # Deleting the Kth element in LL
    if not head:
        return None

    elif k == 1:
        head = head.next

        return head

    else:
        cnt = 0
        temp = head
        pre = None

        while temp:

            cnt += 1

            if cnt == k:
                pre.next = pre.next.next
                del temp
                break

            pre = temp
            temp = temp.next

        return head


def deleteValue(head, val):     # Deleting the val from the LL
    if not head:
        return None

    elif head.data == val:
        head = head.next

        return head

    else:
        temp = head
        pre = None

        while temp:
            if temp.data == val:
                pre.next = pre.next.next
                del temp
                break

            pre = temp
            temp = temp.next

        return head


if __name__ == "__main__":

    arr = [2,3,4,5,6]

    head = convertArraytoLinkedList(arr) #O(N)

    display(head)

    # Deleting the head of linked list
    # head = deleteHead(head)

    # Deletinmg the tail of the libnked list 
    # head = deleteTail(head)

    # Deleteing the Kth element of the Linked list
    # head = deleteKth(head, 6)

    # Deleteing by the value
    head = deleteValue(head, 1)


    display(head)
