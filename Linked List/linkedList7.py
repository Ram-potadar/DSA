"""
Inserting operation 

"""


class Node:
    def __init__(self, data, next = None, back = None):

        self.data = data
        self.next = next
        self.back = back

    
class Solution:

    def addHead(self, data, head):

        node = Node(data, head)

        head.back = node

        return node
    
    def addTail(self, data, head):

        # node = Node(data)


        node = head
        while  node.next:
            node = node.next

        temp = Node(data)
        node.next = temp
        temp.back = node

        return head
    
    def addAfter(self, x, head):

        
    

if __name__ == "__main__":


    head = Node(1)

    node1 = Node(2, None, head)
    head.next = node1

    node2 = Node(3, None, node1)
    node1.next = node2

    obj = Solution()
    # Adding at head 
    # new_head = obj.addHead(12, head)
    # print(new_head.data)

    # Adding at tail
    new_head = obj.addTail(5, head)
    print(head.next.next.next.back.data)

