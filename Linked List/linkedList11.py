"""
    sort 0s, 1s, and 2s nodes
"""

class Node:
    def __init__(self, val , next = None):

        self.val = val
        self.next = next

class Solution:

    def sort(self, head):

        zeroHead = Node(-1)
        oneHead = Node(-1)
        twoHead = Node(-1)

        zero = zeroHead
        one = oneHead
        two = twoHead


        temp = head

        while temp:
            if temp.val == 0:
                zero.next = temp
                zero = temp


            elif temp.val == 1:
                one.next = temp
                one  = temp

            else:
                two.next = temp
                two = temp


            temp = temp.next

        
        zero.next = oneHead.next if oneHead.next else twoHead.next
        one.next =  twoHead.next
        two.next = None

        return zeroHead.next
    


if __name__=="__main__":

    head = Node(0)
    node1 = Node(1)
    head.next = node1

    node2 = Node(2)
    node1.next = node2

    node3 = Node(1)
    node2.next = node3

    node4 = Node(0)
    node3.next = node4


    sol = Solution()


    head = sol.sort(head)

    print(head.next.next.next.next.val)


    

    





