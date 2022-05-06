#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Creates Node
void insertNode( Node ** head, int num ) {

    Node* newNode = ( Node* ) malloc ( sizeof(Node) );

    newNode->data = num;
    newNode->next = (*head);
    newNode->prev = NULL;

    if ( (*head) != NULL ) {
        (*head)->prev = newNode;
    }

    (*head) = newNode;
}

// Adds Node at the end (appends)
void insertAtEnd (  Node ** head, int num ) {

    Node* newNode = ( Node* ) malloc ( sizeof(Node) );

    Node* last = *head;

    newNode->next = NULL;
    newNode->data = num;

    if ( *head == NULL ) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}

// Prints the list from a given node
void printList ( struct Node * node ) {

    // Controles if the list has only one Node
    int flag = 0;

    Node* last;
    if ( node->next == NULL ){
        printf("Backwards is same as Forwards: \n");
        printf(" %d \n", node->data );
        flag = 1;
    }
    if ( flag == 0 ) {
        printf("\nForward:\n");
        while ( node != NULL ){
            printf(" %d ", node->data);
            last = node;
            node = node->next;
        }
        printf("\nBackwards:\n");
        while ( last != NULL){
            printf(" %d ", last->data);
            last = last->prev;
        }
        printf("\n");
    }
}

// Deletes a single Node
// If you want to delete whole List, just run this in for loop
void delNode ( Node ** head, Node * nodeToDel ) {

    if ( (*head) == NULL 
      || nodeToDel == NULL ) {
          return;
    }
    if ( (*head) == nodeToDel ) {
        (*head) = nodeToDel->next;
    }
    if ( nodeToDel->next != NULL ) {
        nodeToDel->next->prev = nodeToDel->prev;
    }
    if ( nodeToDel->prev != NULL ) {
        nodeToDel->prev->next = nodeToDel->next;
    }
    free(nodeToDel);
}

// Deletes Node at specific position
void delNodeAt (Node ** head, int pos ) {
    if ( (*head) == NULL || pos <= 0 ) {
        return;
    }

    Node * curr = (*head);

    for (int i = 1; curr != NULL && i < pos; i++ ) {
        curr = curr->next;
    }
    if ( curr == NULL ) {
        return;
    }
    delNode( head, curr );
}

// Reverses list
void reverse( Node ** head ) {

    Node * tmp = NULL;
    Node * curr = (*head);

    while (curr != NULL) {
        tmp = curr->prev;
        curr->prev = curr->next;
        curr->next = tmp;
        curr = curr->prev;
    }

    if ( tmp != NULL ) {
        (*head) = tmp->prev;
    }
}

int main ( void ) {

    // Needs to create empty array
    struct Node* head = NULL;

    insertNode(&head, 6);
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertAtEnd(&head, 3);
    printList(head);

    printf("\nReversing!\n");
    reverse(&head);
    printList(head);

    delNodeAt( &head, 2 );
    printList(head);

    delNode(&head, head);
    printList(head);

    printf("\nReversing!\n");
    reverse(&head);
    printList(head);

    return 0;
}
