#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * read_files(void * address);

int main(int argc, char * argv[]) {
    char file_1[] = "human_gene.fasta";
    char file_2[] = "mouse_gene.fasta";
    char file_3[] = "yeast_gene.fasta";

    pthread_t thread_1, thread_2, thread_3;
    char * data_1, * data_2,  * data_3;

    pthread_create(&thread_1, NULL, read_files, file_1);
    pthread_create(&thread_2, NULL, read_files, file_2);
    pthread_create(&thread_3, NULL, read_files, file_3);

    pthread_join(thread_1, (void **)&data_1);
    pthread_join(thread_2, (void **)&data_2);
    pthread_join(thread_3, (void **)&data_3);

    printf("%s\n", data_1);
    printf("%s\n", data_2);
    printf("%s\n", data_3);

    free(data_1);
    free(data_2);
    free(data_3);

    return 0;
}

void * read_files(void * address) {
    char * filename = (char *)address;
    FILE * fptr;

    fptr = fopen(filename, "r");
    if (!fptr) {
        perror("error with filepointer");
        return NULL;
    }

    // seek the end of the file
    fseek(fptr, 0, SEEK_END);
    long fsize = ftell(fptr);
    rewind(fptr);

    char *buffer = malloc(fsize + 1);
    if (!buffer) {
        perror("error creating buffer");
        fclose(fptr);
        return NULL;
    }

    

    size_t read = fread(buffer, 1, fsize, fptr);
    buffer[read] = '\0';

    fclose(fptr);
    return buffer;
}