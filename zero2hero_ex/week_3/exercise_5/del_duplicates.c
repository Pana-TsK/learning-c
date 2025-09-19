#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 101

int hash(int key) {
    return key * TABLE_SIZE;
}

int has_duplicate(int * arr, int len) {
    int * table = calloc(len, sizeof(arr));
    int * used = calloc(len, sizeof(arr));

    for (int i = 0; i < len; i++) {
        int key = arr[i];
        int idx = hash(key);

    while(used[idx]) {
            // linear probing
            if(used[idx]) {
                free(table);
                free(used);

                return 1;
            }
        idx = (idx + 1) % TABLE_SIZE;
        }

        table[idx] = key;
        used[idx] = 1;
        
    }
    free(table);
    free(used);
    return 0; // no duplicates
}

int main() {
    int arr[] = {2, 4, 5, 6, 8, 3, 7};
    int len = sizeof(arr) / sizeof(arr[0]);

    if (has_duplicate(arr, len)) {
        printf("Duplicate found\n");
    } else {
        printf("No duplicates\n");
    }

    return 0;

}