#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * prev;
    struct node * next;
} node;

typedef struct dll {
    node * sentinel;
    int length;
} doubll;

doubll * init() {
    doubll * list = malloc(sizeof(doubll));
    node * sentinel = malloc(sizeof(node));

    list->sentinel = sentinel;

    list->sentinel->next = list->sentinel;
    list->sentinel->prev = list->sentinel;

    return list;
}

void insert_end(doubll * list, int val) {

    node * temp = malloc(sizeof(temp));
    node * last = list->sentinel->prev;

    temp->val = val;

    temp->next = list->sentinel;     // new tail points to sentinel
    temp->prev = last;               // back-link to old tail

    last->next = temp;               // old tail forward-link to new node
    list->sentinel->prev = temp;     // sentinel back-link to new tail
    
}

void insert(doubll * list, int pos, int val) {

    node * newnode = malloc(sizeof(node));
    node * curr_node = list->sentinel;

    newnode->val = val;

    for(int i = 0; i <= pos; i++) {
        curr_node = curr_node->next;
        
        if (curr_node == list->sentinel) {
        fprintf(stderr, "the provided positional value is out-of-scope.\n");
        return;
        }
    }

    // link in the current node 
    node * prev = curr_node->prev;

    prev->next = newnode;
    newnode->prev = prev;

    curr_node->prev = newnode;
    newnode->next = curr_node;


}

void print(doubll * list) {

    node * current = list->sentinel->next;
    while (current != list->sentinel) {
        printf("%d", current->val);
        if (current->next != list->sentinel) {
            printf(", ");
        }
        current = current->next;
    }
    printf("\n");

}



int main() {
    doubll * ex = init();

    insert_end(ex, 4);
    insert_end(ex, 5);
    insert_end(ex, 12);

    print(ex);

    insert(ex,2, 7);
    
    print(ex);

    insert(ex,6, 7);

    print(ex);

    return 0;
}