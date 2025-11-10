"""
Array to Double linked list

"""


class Node:
    def __init__(self, data , next = None, back = None):
        self.data = data
        self.next = next
        self.back = back



class Solution:

    def arrayToDLL(self, arr):

        head = Node(arr[0])

        pre = head

        for i in arr[1:]:
            temp = Node(i)

            temp.back = pre
            pre.next = temp
            pre = temp


        return head
    

if __name__ == "__main__":

    arr = [1, 2, 3, 4]

    sol = Solution()

    head = sol.arrayToDLL(arr)

    print(head.data)
    print(head.next.next.back.back.data)
    print(head.next.next.next.next)
    print(head.back)