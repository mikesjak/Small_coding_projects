# Defines what is in Node
from re import L


class Node():

    def __init__( self,data ):
        self.key = data
        self.left = None
        self.right = None

# Printing function from left to right
def inorder( tmp ):

    if ( not tmp ):
        return
    
    inorder(tmp.left)
    print(tmp.key, end = " ")
    inorder(tmp.right)

# Inserts Node at the first missing place 
# Again going from left to right
def insert( tmp, key ):

    if not tmp:
        root = Node(key)
        return
    q = []
    q.append(tmp)

    while (len(q)):
        tmp = q[0]
        q.pop(0)
        if (not tmp.left):
            tmp.left = Node(key)
            break
        else:
            q.append(tmp.left)
        if (not tmp.right):
            tmp.right = Node(key)
            break
        else:
            q.append(tmp.right)

def deleteDeepest( root, delNode ):
    q = []
    q.append(root)
    while(len(q)):
        tmp = q.pop(0)
        if tmp == delNode:
            tmp.right = None
            return
        if tmp.right:
            if tmp.right == delNode:
                tmp.right = None
            else:
                q.append(tmp.right)
        if tmp.left:
            if tmp.left == delNode:
                tmp.left = None
                return
            else:
                q.append(tmp.left)

def deleteNode( root, key ):
    if root == None:
        return None
    if root.left == None and root.right == None:
        if root.key == key:
            return None
        else:
            return root
    q = []
    q.append(root)

    tmp = None
    keyNode = None

    while(len(q)):
        tmp = q.pop(0)
        if tmp.key is key:
            keyNode = tmp
        if tmp.left:
            q.append(tmp.left)
        if tmp.right:
            q.append(tmp.right)
    if keyNode:
        x = tmp.key
        deleteDeepest(root, tmp)
        keyNode.key = x
    return root

# Testing function
if __name__ == '__main__':
    root = Node(2)
    root.left = Node(9)
    root.left.left = Node(7)
    root.right = Node(3)
    root.right.left = Node(1)
    root.right.right = Node(0)

# 'end = " "' makes that inorder doesn't print at a new line.
    print("Inorder:", end = " ")
    inorder(root) 
    print()

    insert(root,8)
    
# 'end = " "' makes that inorder doesn't print at a new line.
    print("Imorder:", end = " ")
    inorder(root)
    print()

    root = deleteNode(root, 74)

    print("After deletion:", end = " ")
    inorder(root)
    print()
