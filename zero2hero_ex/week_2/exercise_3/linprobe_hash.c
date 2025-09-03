#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    int value;
    int occupied;
} Node;

#define VOID_NODE (Node){ .key = -1, .value = 0 }

typedef struct hashmap {
    Node * arr;
    size_t capacity;
    size_t len;
} hashmap;

hashmap * init(int initial_capacity) {
    hashmap * map = malloc(sizeof(hashmap));
    
    map->arr = malloc(initial_capacity * sizeof(Node));
    
    if (!map->arr) {
        fprintf(stderr, "error while allocating the space for the hashmap.\n");
    }

    for(int i = 0; i < initial_capacity; i++) {
        map->arr[i] = VOID_NODE;
    }

    map->capacity = (size_t)initial_capacity;
    map->len = 0;

    return map;
}

int hashindex(hashmap * map, int key) {
    return (int)(key % map->capacity);
}

void insert(hashmap * map, int key, int value) {

    Node temp_node = {key, value};
    int hcode = hashindex(map, key);

    // iterate over the array from the index onward
    // if there is an item already present at the index, we move to the next location.

    for(int i = hcode; (i+1) != hcode ; i = (i + 1) % map->capacity) {
        if(!map->arr[i].occupied) {
            map->arr[i] = temp_node;
            map->arr[i].occupied = 1;
            return;
        }
    }
    
    fprintf(stderr, "The array is full. Consider initiating with more size.\n");
}

void delete(hashmap * map, int key) {
    int hashcode = hashindex(map, key);

    for (int i = hashcode; (i+1) != hashcode ; i = (i + 1) % map->capacity) {
        if (map->arr[i].key == key && map->arr[i].occupied) {
            map->arr[i].value = 0;
            map->arr[i].occupied = 0;

            printf("succesfully deleted node with key %d\n", key);

            return;
        } 
    }
    printf("deleting %d failed: value not found in array.", key);
}


void print(hashmap * map) {
    printf("printing the array:\n");
    for (int i = 0; i < map->capacity; i++){
        printf("key: %d   value: %d\n", map->arr[i].key, map->arr[i].value);
    }
}


int main () {
    hashmap * h = init(10);
    printf("hashmap length: %ld\n", h->capacity);

    int example = hashindex(h, 23);
    printf("hash encoding: %d\n", example);

    insert(h, 10, 10);
    insert(h, 11, 11);
    insert(h, 13, 6);
    insert(h, 23, 7);
    insert(h, 33, 7);

    print(h);

    delete(h, 23);
    delete(h, 23);

    print(h);
    
    return 0;
}