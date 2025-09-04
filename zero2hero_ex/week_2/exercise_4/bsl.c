#include <stdio.h>
#include <stdlib.h>

typedef struct binary_node {
    struct binary_node * left;
    struct binary_node * right;
    int val;
} node;

node * init(int value) {
    node * start = malloc(sizeof(node));

    start->val = value;

    return start;
}

void insert(node * tree, int value) {
    node * curr_ptr = tree;
    node * parent = NULL;

    while (curr_ptr) {

        parent = curr_ptr;

        if (value < curr_ptr->val) {
            curr_ptr = curr_ptr->left;
        } else if (value > curr_ptr->val) {
            curr_ptr = curr_ptr->right;
        } else{
            fprintf(stderr, "value is already in the hashmap.\n");
            return;
        }
    }
    
    node * new_node = malloc(sizeof(node));
    new_node->val = value;

    if (value < parent->val) {
        parent->left = new_node;
    } else if (value > parent->val) {
        parent->right = new_node;
    }
}

node * search (node * root, int value) {
    node * curr_ptr = root;
    node * parent = NULL;

    while (curr_ptr) {

        parent = curr_ptr;

        if (value < curr_ptr->val) {
            curr_ptr = curr_ptr->left;
        } else if (value > curr_ptr->val) {
            curr_ptr = curr_ptr->right;
        } else if (value == curr_ptr->val){
            return curr_ptr;
        }
    }

}

node * delete_node (node * root, int value) {
    if (!root) return NULL;

    if (value < root->val) {
        root->left = delete_node(root->left, value);
    } else if (value > root->val) {
        root->right = delete_node(root->right, value);
    } else {
        // Node found
        if (!root->left) {
            node* temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            node* temp = root->left;
            free(root);
            return temp;
        } else {
            // Node with two children
            node* temp = root->right;
            while (temp->left) temp = temp->left; // find inorder successor
            root->val = temp->val;
            root->right = delete_node(root->right, temp->val);
        }
    }
    return root;
}



void print_tree(node *root, int depth) {
    if (!root) return;
    
    print_tree(root->right, depth + 1);
    for (int i = 0; i < depth; i++) {
        printf("    ");  // 4 spaces per depth
    }
    printf("%d\n", root->val);
    print_tree(root->left, depth + 1);

}

void print_in_order(node * root) {

    if (!root) return;

    if (root->left) {
        print_in_order(root->left);
    }

    printf("%d  ", root->val);

    if (root->right) {
        print_in_order(root->right);
    }

}


int main() {
    node * bst = init(14);

    insert(bst, 5);
    insert(bst, 22);
    insert(bst, 16);
    insert(bst, 18);

    insert(bst, 7);
    insert(bst, 9);
    insert(bst, 23);

    print_tree(bst, 0);
    printf("\n======================\n\n");

    node * del = delete_node(bst, 7);
    print_tree(del, 0);

    print_in_order(bst);

    node * x = search(bst, 23);
    printf("found value %d\n", x->val);
    return 0;
}