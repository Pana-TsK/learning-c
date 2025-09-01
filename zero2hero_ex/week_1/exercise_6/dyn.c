#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

double ** array(char * s, int * n_rows, int ** row_lengths);
void print_array(char ** arr);

int main() {
    char *s = "[[1 2 46] [8.12 10]]";
    int n_rows = 0;
    int * row_lengths;

    double ** arr = array(s, &n_rows, & row_lengths);

     for (int i = 0; i < n_rows; i++) {
        printf("[");
        for (int j = 0; j < row_lengths[i]; j++) {
            printf("%.1f ", arr[i][j]);
        }
        printf("]\n");
    }
    
    free(arr);
    free(row_lengths);

    return 0;
}

/* array builder. Handles iteration between objects, and acts as a manager.*/
double ** array(char * s, int * n_rows, int ** row_lengths) {
    int col_bufsize = 4;
    int row_bufsize = 16;

    int nesting = 0;

    // allocate the space for the row_lengths
    * row_lengths = malloc(col_bufsize * sizeof(int));
    // allocate the space for the arrays
    double ** array = malloc(row_bufsize * sizeof(double *));

    // ignore leading spaces
    while (isspace(* s)) {
        s++;
    }

    

    // include error handling for the first character having to be a '['.
    if (* s != '[') {
        fprintf(stderr, "Error: the array does not start with opening brackets.\n");
        return NULL;

    }

    // set the null pointer
    // if this is the only row we come across, row will be added to the array as a single row.
    double * row = malloc(row_bufsize * sizeof(double));

    s++;
    nesting++;

    // jagged index
    int j = 0;
    int i = 0;

    for(; *s != '\0' && nesting != 0; s++) {
        if (*s == '[') {
            row = malloc(row_bufsize * sizeof(double));
            nesting++;

            // individual row array index and row 
            i = 0;

        } else if (isdigit(*s) || * s == '-') {
            // grab the full number
            char * endptr;
            double digit = strtod(s, &endptr);
            s = endptr - 1;

            // perform check to see whether row_length is not exceeded
            if (i >= row_bufsize) {
                row_bufsize *= 2;
                double * temp_ptr = realloc(row, row_bufsize * sizeof(double));

                if (! temp_ptr) {
                    fprintf(stderr, "Error allocating space for row length increase.\n");
                    return NULL;
                }
                row = temp_ptr;
            }

            // append to the row
            row[i++] = digit;

        } else if (*s == ']') {

            nesting--;
            // signals either the end of a row, or the end of the array.
            if (nesting == 1) {

                // check if the array is long enough for further appending
                if (j >= col_bufsize) {
                    double ** temp_ptr1 = realloc(array, col_bufsize * sizeof(double *));
                    int * temp_ptr2 = realloc(*row_lengths, col_bufsize * sizeof(int));

                    if (!temp_ptr1 || !temp_ptr2) {
                        fprintf(stderr, "Error reallocating space for rows\n");
                        return NULL;
                    }

                    array = temp_ptr1;
                    *row_lengths = temp_ptr2;
                }

                // append the array with the row, and append the row_lengths
                array[j] =  row;
                (*row_lengths)[j] = i;
                j++;

                * n_rows = j;
                }
            }
        }
    return array;
}