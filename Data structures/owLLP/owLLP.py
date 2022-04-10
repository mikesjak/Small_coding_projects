from operator import index

# Defines what Node has
class Node:
    def __init__( self, data = None, next = None ):
        self.data = data
        self.next = next

#Defines LinkedList and all the functions with it
class LinkedList:
    def __init__( self ):
        self.head = None

    # Creates a node and puts it at the beggining of a LL
    def insertAtStart( self, data ):
        node = Node( data, self.head )
        self.head = node

    ## Creates a node and puts it at the end of a LL
    def insertAtEnd( self, data ):
        if self is None:
            self.head = Node( data, None )
            return

        curr = self.head
        while curr.next:
            curr = curr.next
            
        curr.next = Node( data, None )

    # Counts lenght
    def lenghtCounter(self):
        lenght = 0
        curr = self.head
        while curr:
            lenght+=1
            curr = curr.next
        
        return lenght

    # Removes a node a 'index' position
        # REMEMBER, we count from 0
    def removeAt( self, index ):
        if index < 0 or index >= self.lenghtCounter():
            raise Exception("Invalid index")
        
        if index == 0:
            self.head = self.head.next
            return
        
        count = 0
        curr = self.head

        while curr:
            if count == index - 1:
                curr.next = curr.next.next
                break
            curr = curr.next
            count +=1

    # Creates a node and puts it at 'index' position
    def insertAt( self, index, data ):
        if index < 0 or index >= self.lenghtCounter():
            raise Exception("Invalid index")

        if index == 0:
            self.insertAtStart( data )
            return
        
        count = 0
        curr = self.head
        while curr:
            if count == index - 1:
                node = Node( data, curr.next )
                curr.next = node
                break

            curr = curr.next
            count += 1
    
    # Prints whole list
    def print( self ):
        if self.head is None:
            print("Linked list is empty.")
            return
        curr = self.head
        llstr = ''
        while curr:
            llstr += str( curr.data ) + ' --> '
            curr = curr.next
        
        print( llstr )

# Here are just some cases of how to use this LL set.
if __name__ == '__main__':
    ll = LinkedList()
    ll.insertAtStart(1)
    ll.insertAtStart(3)
    ll.insertAtStart(8)
    ll.insertAtEnd(88)
    ll.print()
    print("Lenght:", ll.lenghtCounter())
    ll.removeAt(2)
    ll.insertAt(1, 5)
    ll.print()


