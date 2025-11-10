"""
    Insertion of node


"""

class Node:

    def __init__(self, data, next = None):

        self.data = data
        self.next = next


class LinkedList:

    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return 
        current = self.head
        while current.next :
            current = current.next
        current.next = new_node

    def display(self):

        temp = self.head
        while temp:
            print(temp.data, end=" ")
            temp = temp.next
        

    def insertionHead(self, data):
        new_node = Node(data)

        if not self.head:
            return new_node
    
        temp = new_node
        temp.next = self.head
        self.head = temp

    def insertTail(self, data):

        new_node = Node(data)
        if not self.head:
            return new_node
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = new_node

        
    def insetatKthPos(self, data, k):

        new_node = Node(data)

        if not self.head:
            return new_node
        
        elif k == 1:
            self.head.next = new_node
            return self.head

        else:

            cnt = 0
            temp = self.head
            while temp:
                cnt += 1
                if cnt == k-1:
                    new_node.next = temp.next
                    temp.next = new_node

                temp = temp.next


            return self.head
        

    def insetatbeforeValue(self, data, val):

        new_node = Node(data, self.head)

        if not self.head:
            return None
        
        elif val == self.head.data:
           
            return Node(data, self.head)

        else:

            temp = self.head
            while temp:
                if val == temp.next.data:
                    # new_node.next = temp
                    temp.next = new_node

                temp = temp.next


            return self.head
        
    
if __name__ == "__main__":
    l1 = LinkedList()
    l1.append(1)
    l1.append(2)
    l1.append(3)
    l1.append(4)
    l1.append(5)

    l1.display()
    
    # print("\nInserting the head..")
    # l1.insertionHead(7)

    # print("\nInserting the tail..")
    # l1.insertTail(8)

    print("\nInserting at Kth position..")
    l1.insetatKthPos(7, 6)

    l1.display()

    