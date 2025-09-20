#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define BUFFSIZE 64

static void print_array(double * buffer, size_t buff_length);

size_t read_data(char * filename, double ** data_array, size_t buffsize);

int main(int argc, char ** argv) 
{
    double * data = NULL;
    size_t file_length = read_data("wave.txt", &data, BUFFSIZE);

    print_array(data, file_length);

    free(data);
    return 0;
}


size_t read_data(char * filename, double ** data_array, size_t buffsize)
{
    FILE * fptr;
    char * text_buffer;
    
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        perror("error reading in file");
        exit(1);
    }

    // allocate the memory for the text buffer
    * data_array = malloc(sizeof(double) * buffsize);
    if (* data_array == NULL) {
        perror("error allocating the text buffer");
        exit(1);
    }

    size_t count = 0;
    double temp_val;

    while(fscanf(fptr, "%lf", &temp_val) == 1) {

        if (count > buffsize) {
            buffsize *= 2;
            double * temp_ptr = realloc(* data_array, sizeof(double) * buffsize);

            if(!temp_ptr) {
                perror("error re-allocating array with input data");
                exit(1);
            }
            * data_array = temp_ptr;
        }
        (* data_array)[count++] = temp_val;
    }

    // reduce the array memory size to match the amount of entries

    double * final_ptr = realloc(* data_array, sizeof(double) * count);
    if (final_ptr != NULL) {
        * data_array = final_ptr;
    }

    return count;

}

static void print_array(double * buffer, size_t buff_length) 
{
    for (int i = 0; i < buff_length; i++){
        printf("%f ", buffer[i]);
    }
    printf("\n");
}