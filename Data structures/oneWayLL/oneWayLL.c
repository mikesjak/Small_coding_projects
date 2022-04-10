/*-----------------------------------------------------------------------------------+
        This branch will show you, how to work with one direction Linked lists.      |
        We will do some basic functions.                                             |
            - Creating Node                                                          |
            - Deleting LL step by step, emptying list                                |
            - Adding Nodes to the start                                              |
            - Printing the LL                                                        |
            - Counting the lenght of the list                                        | 
------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

// Struct that defines the Linked list
typedef struct Node {
    int m_Data;
    struct Node * m_Next;
} Node;

// Creates an empty list
void listCreate ( Node ** head ) {
    *head = NULL;
}

// Makes sure, the list is NULL when deleted
int listEmpty ( Node * head ) {
    return head == NULL;
}

// Creates single node
Node * createNode ( int data, Node * next ) {
    Node * list = (Node *) malloc (sizeof(*list) );
    list->m_Data = data;
    list->m_Next = next;
    return list;
}

// Deletes single node
Node * nodeDelete ( Node * list ) {
    Node * next = list->m_Next;
    free(list);
    return next;
}

// Adds node to the beggining of the list
void listPush ( Node ** head, int data ) {
    *head = createNode( data, *head );
}

// Deletes list
void  listDelete ( Node ** head ) {
    Node * current = *head;
    while ( current != NULL ) {
        current = nodeDelete( current );
    }
    *head = NULL;
}

// Gets size of the list
size_t listLenght ( Node * head ) {
    size_t lenght = 0;

    Node * current = head;
    while ( current != NULL ) {
        lenght++;
        current = current->m_Next;
    }
    return lenght;
}

// Prints the list
void listPrint ( Node * head ) {
    Node * current = head;
    printf("Head");
    while ( current != NULL ) {
        printf(" -> %d", current->m_Data);
        current = current->m_Next;
    }
    printf("\n");
}

int main ( void ) {

    Node * head = NULL;
    int data;

    listCreate ( &head);
    
    while ( scanf(" %d", &data) == 1 ){
        listPush( &head, data );
    }
    
    listPrint( head );

    printf("Lenght is %d.\n", (int)listLenght(head));

    return 0;
}
