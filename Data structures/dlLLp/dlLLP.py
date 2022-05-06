
# Garbage collector
import gc

# Defines what Node has
class Node:
    def __init__( self, data ):
        self.data = data
        self.next = None
        self.prev = None

# Defines Linked List and all the wunftions with it
class LinkedList:
    def __init__( self ):
        self.head = None

    # Creates a node and puts is at the beggining of a LL
    def insertAtStart( self, newData ):

        new = Node(newData)
        new.next = self.head
        
        if self.head is not None:
            self.head.prev = new
        
        self.head = new

    # Creates a node and puts it at the end of a LL
    def insertAtEnd( self, newData ):

        newNode = Node( newData )
        if self.head is None:
            self.head = newNode
            return
        
        last = self.head
        while last.next:
            last = last.next
        
        last.next = newNode
        newNode.prev = last

    # Creates a node nad puts it after prevNode
    def insertAfter( self, prevNode, newData ):

        if prevNode is None:
            print("Previous Node can't be None")

        newNode = Node( newData )

        newNode.next = prevNode.next
        prevNode.next = newNode
        newNode.prev = prevNode

        if newNode.next:
            newNode.next.prev = newNode

    # Counts lenght
    def lenghtCounter( self ):

        lenght = 0
        curr = self.head
        while curr:
            lenght+=1
            curr = curr.next
        
        return lenght
    
    # Removes node at pos
    def removeNode( self, pos ):

        if self.head is None or pos is None:
            return
        
        if self.head == pos:
            self.head = pos.next
        
        if pos.next is not None:
            pos.next.prev = pos.prev
        
        if pos.prev is not None:
            pos.prev.next = pos.next
        
        gc.collect()

    # Printing function.
    def print( self, lenght):
        if self.head is None:
            print("Linked list is empty.")
            return
        curr = self.head
        count = 1
        llstr = ''
        while curr:
            llstr += str( curr.data ) 
            if count != lenght:
                llstr += ' <---> '
            curr = curr.next
            count += 1
        print( llstr )

# Testing funtion
if __name__ == '__main__':
    ll = LinkedList()
    ll.insertAtStart(1)
    ll.insertAtStart(3)
    ll.insertAtStart(8)
    ll.insertAtEnd(88)
    ll.print( ll.lenghtCounter() )

    ll.removeNode(ll.head)
    ll.print( ll.lenghtCounter() )
    print( "Lenght:", ll.lenghtCounter() )

    ll.insertAtStart(8)
    ll.insertAtEnd(99)
    ll.print(ll.lenghtCounter() )
    print( "Lenght:", ll.lenghtCounter() )
