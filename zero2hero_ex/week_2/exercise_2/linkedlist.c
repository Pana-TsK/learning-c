#include <stdio.h>
#include <stdlib.h>

/* ---------------- Struct definitions ----------------*/
typedef struct node {
    int i;
    struct node * next;
} Node;

typedef struct linkedlist_struct {
    Node * head;
    Node * tail;
    size_t size;
} LinkedList;

/* Create a new node */
Node * createNode(int num) {
    Node * newnode = (Node *)malloc(sizeof(Node));
    if (!newnode) {
        exit(1);
    }

    newnode->i = num;
    newnode->next = NULL;

    return newnode;
}
/* push node onto singly linked list */
void LinkedList_push(LinkedList * list, int num) {
    Node * newnode = createNode(num);

    if(list->head == NULL) {
        list->head = newnode;
        list->tail = newnode;
        list->size = 1;
    } else {
        list->tail->next = newnode;
        list->tail = newnode;
        list->size++;
    }
}

/* print every item in linked list */
void print_list(LinkedList * list) {
    
    //set the current node to the beginning of the list
    Node * curr_node = list->head;

    while (curr_node) {
        printf("%d ", curr_node->i);
        curr_node = curr_node->next;

    }

    printf("\n");
}

/* remove head of linked list (O(n) operation)*/
void LinkedList_remove(LinkedList * list, int num) {

    Node * curr_node = list->head;

    if (!curr_node) {
        exit(1);
    }

    if (curr_node->i == num) {
        list->head = curr_node->next;
        free(curr_node);

        return;
    }

    while(curr_node && curr_node->next) {
        if (curr_node->next->i == num) {
            
            if (curr_node->next->next) {
            
            Node * to_delete = curr_node->next;
            curr_node->next = curr_node->next->next;
            free(to_delete);
            
            list->size--;
            return;
            }
        }
        curr_node = curr_node->next;
    } 
}

int LinkedList_find(LinkedList * list, int num) {
    Node * curr_node = list->head;

    while(curr_node) {
        if (curr_node->i == num) {
            return 1;
        }
        curr_node = curr_node->next;
    }
    return 0;
}


int main() {

    LinkedList list;

    LinkedList_push(&list, 10);
    LinkedList_push(&list, 20);
    LinkedList_push(&list, 30);
    LinkedList_push(&list, 40);

    print_list(&list);

    LinkedList_remove(&list, 30);
    
    print_list(&list);

    int found = LinkedList_find(&list, 30);
    int found_2 = LinkedList_find(&list, 40);

    printf("%d\n%d\n", found, found_2);

}