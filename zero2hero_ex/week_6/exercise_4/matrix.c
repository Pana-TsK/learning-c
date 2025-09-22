#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUFSIZE 128

/* matrix handling utils */
double ** create_matrix(size_t * n_rows, size_t * n_cols);
void print_array(double ** matrix, size_t n_rows, size_t n_cols);

/* matrix transposing & multiplication */
double ** transpose(double ** matrix, size_t n_rows, size_t n_cols, size_t * tn_rows, size_t * tn_cols);
void cleanup(double ** matrix, size_t n_rows);

int main(int argc, char ** argv)
{
    size_t n_rows, n_cols;
    double ** matrix = create_matrix(&n_rows, &n_cols);
    print_array(matrix, n_rows, n_cols);

    size_t t_rows, t_cols;
    double ** t_mat = transpose(matrix, n_rows, n_cols, &t_rows, &t_cols);
    print_array(t_mat, t_rows, t_cols);

    cleanup(matrix, n_rows);
    return 0;
}

/* function uses scanf to create a new matrix*/
double ** create_matrix(size_t * n_rows, size_t * n_cols)
{
    size_t bufsize = BUFSIZE;
    double ** matrix = malloc(sizeof(double *) * bufsize);
    if(!matrix) {
        perror("error allocating mem space for matrix");
        exit(1);
    }

    size_t mat_len = 0;
    size_t row_len, row_cap = BUFSIZE;
    char buf[BUFSIZE];

    printf("Provide matrix input:\n");
    while(fgets(buf, row_cap, stdin) != NULL) {
        // find the length of the buf
        
        row_len = 0;

        // create a row
        double * row = malloc(sizeof(double) * row_cap);
        if (!row) {
            perror("error creating row");
            exit(1);
        }

        // fill in the row by parsing through it;
        double digit;
        char * p = buf;
        char * end;
        // populate the row

        
        while(1) {
            digit = strtod(p, &end);

            if (p == end) { // we break if nothing was parsed
                break;
            }
            if (row_len >= row_cap) {
                row_cap *= 2;
                double * tmp = realloc(row, sizeof(row_cap));
                if (tmp == NULL) {
                    perror("error allocating more space for a row");
                    exit(1);
                }
            }

            row[row_len++] = digit;
            p = end;
        }

        // shrink down row to the correct size
        double * row_fptr = realloc(row, row_len * sizeof(double));
        if (row_fptr) {
            row = row_fptr;
        }

        // if necessary, increase the amount of space allocated to the matrix
        if (mat_len >= bufsize) {
            bufsize *= 2;
            double **tmp = realloc(matrix, bufsize * sizeof(double *));
            if (!tmp) {
                perror("error reallocating matrix");
                exit(1);
            }
            matrix = tmp;
            }

        matrix[mat_len++] = row;
    }

    // reduce the amount of space allocated for the matrix to what is actually necessary
    

    * n_rows = mat_len;
    * n_cols = row_len;
    
    return matrix;
}

void cleanup(double ** matrix, size_t n_rows)
{
    for (int i = 0; i < n_rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void print_array(double ** matrix, size_t n_rows, size_t n_cols)
{
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
        printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/* perform in-place matrix transposition*/
double ** transpose(double ** matrix, size_t n_rows, size_t n_cols, size_t * t_rows, size_t * t_cols)
{
    // dim counters
    * t_rows = n_cols;
    * t_cols = n_rows;

    // allocate the new row space
    double ** t_matrix = malloc(sizeof(double *) * (* t_rows));

    // we will iterate over the old columns, meaning we index first by n_cols 
    for(int j = 0; j < n_cols; j++) {
        double * t_row = malloc(sizeof(double) * (* t_cols)); // we know exactly how long the row has to be.
        
        for (int i = 0; i <  n_rows; i++) { // now iterate over the old rows
            t_row[i] = matrix[i][j];
        }
        t_matrix[j] = t_row;
    }

    return t_matrix;
}