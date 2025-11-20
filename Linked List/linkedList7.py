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
    
    def addBefore(self, x, tar, head):

        if not head:
            return None

        if head.data == tar:
            temp = Node(x, head)
            head.back = temp
            return temp
        

        else:
            node = head

            while node:
                if node.data == tar:
                    temp = Node(x, node)
                    node.back.next = temp
                    temp.back = node.back
                    node.back = temp
                
                    return head
                node = node.next
            return None


        
    

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
    # new_head = obj.addTail(5, head)
    # print(head.next.next.next.back.data)

    # Add at value
    new_head = obj.addBefore(5, 5, head)
    print(new_head.next.data)

