#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

static size_t read_data(char * filename, double ** buffer);
static void print_array(double * buffer, size_t buff_length);

int main(int argc, char * argv[]) 
{
    double * data_buffer = NULL;
    size_t bufflen = read_data("wave.txt", &data_buffer);

    if (data_buffer != NULL) {
        print_array(data_buffer, bufflen);
        free(data_buffer); // Free the dynamically allocated memory
    }

    return 0;
}

static size_t read_data(char * filename, double ** buffer) 
{
    FILE * fptr;
    double temp_val;
    size_t count = 0;
    size_t capacity = 100; // Initial capacity

    // Allocate initial buffer space
    *buffer = malloc(capacity * sizeof(double));
    if (*buffer == NULL) {
        perror("error allocating initial buffer");
        return 0;
    }

    // Open file in text mode
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        perror("error opening file");
        free(*buffer);
        *buffer = NULL;
        return 0;
    }

    // Read numbers one by one from the text file
    while (fscanf(fptr, "%lf", &temp_val) == 1) {
        if (count >= capacity) {
            capacity *= 2;
            double * temp = realloc(*buffer, capacity * sizeof(double));
            if (temp == NULL) {
                perror("error reallocating buffer");
                free(*buffer);
                *buffer = NULL;
                fclose(fptr);
                return 0;
            }
            *buffer = temp;
        }
        (*buffer)[count++] = temp_val;
    }

    fclose(fptr);
    return count;
}

static void print_array(double * buffer, size_t buff_length) 
{
    for (int i = 0; i < buff_length; i++){
        printf("%f ", buffer[i]);
    }
    printf("\n");
}