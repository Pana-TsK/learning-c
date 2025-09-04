#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    int val;
    int psl;
} node;

typedef struct hashmap {
    node * array;
    size_t capacity;
    size_t size;
} hashmap;


hashmap * init(int capacity) {

    hashmap * map = malloc(sizeof(hashmap));

    map->array = malloc(capacity * sizeof(node));
    map->capacity = capacity;
    map->size = 0;

    return map;
}

int hashcode(hashmap * map, int key) {
    return (int)(key % map->capacity);
}


void insert(hashmap * map, int key, int val) {

    node temp_node = {key, val, 0};
    int hcode = hashcode(map, key);

    int vpsl = 0;
    int i;

    for (int i = hcode; (i+1) != hcode; i = (i+1) % map->capacity) {
        vpsl++;

        if(map->array[i].psl < vpsl) {
            node swap_node = map->array[i];
            map->array[i] = temp_node;
            temp_node = swap_node;
        }

        if (map->array[i].key == 0) {
            temp_node.psl = vpsl;
            map->array[i] = temp_node;
            map->size++;

            return;
        }
    }
}

void delete(hashmap * map, int key) {
    int hcode = hashcode(map, key);

    for (int i = hcode; (i+1) != hcode; i = (i+1) % map->capacity) {

        if (map->array[i].key == key) {
            map->array[i].key = 0;
            map->array[i].psl = 0;
            map->array[i].val = 0;
        }

    }
}

void print_hashmap(hashmap * map) {

    printf("printing hashmap:\n");
    for (int i = 0; i < map->capacity; i++) {
        printf("key: %d  value: %d  psl: %d\n", map->array[i].key, map->array[i].val, map->array[i].psl);
    }
}

int main() {
    hashmap * map = init(10);

    insert(map, 11, 20);

    insert(map, 44, 4);

    print_hashmap(map);

    insert(map, 13, 40);
    insert(map, 23, 45);
    insert(map, 33, 33);
    insert(map, 43, 43);

    delete(map, 23);

    print_hashmap(map);
}