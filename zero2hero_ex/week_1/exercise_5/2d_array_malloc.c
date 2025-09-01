/* stimulating a 2D array with malloc */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char * read_input_string();
int read_dims(char *s);
void allocate_space(int ***arr, int rows, int cols);
void build_array(char * arr_text, int *** arr);
    
int n_rows = 0, n_cols = 0;
int nesting = 0;



int main () {
    printf("enter numpy-like arrary:\n");

    char * arr_text = read_input_string();
    int ** arr;

    read_dims(arr_text);
    printf("array with %d x %d\n", n_rows, n_cols);

    allocate_space(&arr, n_rows, n_cols);
    build_array(arr_text, & arr);

    for (int i = 0; i < n_rows; i++) {
    for (int j = 0; j < n_cols; j++) {
        printf("%d ", arr[i][j]);
    }
    printf("\n");  // new line after each row
}

    free(arr_text);
    free(arr);
    return 0;
}

// read the array into memory
char * read_input_string() {
    int buffer_size = 128;
    char * input_string = (char *)malloc(buffer_size * sizeof(char));

    if (!input_string) {
        perror("failed to free memory for input string.");
        return NULL;
    }
    
    int c; //character to be read in
    int current_length = 0; //

    while ((c = getchar()) != EOF) {
        if (current_length >= buffer_size - 1) {
            buffer_size *= 2;
            char * temp_ptr = (char *)realloc(input_string, buffer_size * sizeof(char));

            if (!temp_ptr) {
                perror("failed to free enough memory for input string.");
                return NULL;
            }
            input_string = temp_ptr;
        }
        input_string[current_length++] = (char)c;
        input_string[current_length] = '\0';
    }

    // after all the input, if nothing was read, free the memory
    if (current_length == 0) {
        free(input_string);
        return NULL;
    }

    // shrink to the exact size of the final string
    char * final_string = (char *)realloc(input_string, (current_length + 1) * sizeof(char));
    if (!final_string) {
        return input_string;
    }
    
    return final_string;
}

void skip_whitespace(char ** ptr);
void account_for_number (char ** ptr);

int read_dims(char *s) {
    n_rows = 0;
    n_cols = 0;
    nesting = 0;

    int temp_n_cols;

    char * current_char_ptr = s; // pointer to transverse the string.

    // check for initial '['
    if (* current_char_ptr != '[') {
        fprintf(stderr, "Error: input must start with '['\n");

        return -1;
    }

    current_char_ptr++;
    nesting++;

    while (* current_char_ptr != '\0') {
        skip_whitespace(& current_char_ptr);

        if (*current_char_ptr == '[') {
            if (nesting > 2) {
                fprintf(stderr, "Error: nesting is too deep. More than 2 dimensions.\n");

                return -1;
            }
        current_char_ptr++;
        nesting++;
        n_rows++;
        
        temp_n_cols = 0;

        }
        else if (*current_char_ptr == ']') {
            current_char_ptr++;
            nesting--; // consume a row

            if (n_cols == 0) { // meaning we came across the very first column
                n_cols = temp_n_cols;
            } else if (temp_n_cols != n_cols && temp_n_cols != 0) { // column mismatch over the rows
                fprintf(stderr, "Error: difference in column length over rows.\n");

                return -1;
            }
            
        }

        else if (isdigit(*current_char_ptr) || *current_char_ptr == '-') {
            account_for_number(& current_char_ptr);
            temp_n_cols++;
        }

        
    }

    // handling a row instead of an array
    if (n_rows == 0) {
        n_rows++;
    }

return 0;
}
 
void skip_whitespace(char ** ptr) {
    while (**ptr != '\0' && isspace(**ptr)) {
        (*ptr)++;
    }
}

void account_for_number(char ** ptr) {
    while ( **ptr != '\0' && ** ptr != ' ' && (isdigit( **ptr) || **ptr == '.' || **ptr == '-')  ) {
        (*ptr)++;

    }
}

/* Allocate the space for multiple arrays: one with n_rows elements, the other with n_cols elements */
void allocate_space(int ***arr, int rows, int cols)  { // *** due to needing a pointer to a pointer, of which we will need to pass the address
    // allocate the memory space for the amount of rows
    * arr = (int **)malloc(rows * sizeof(int *));
    if (*arr == NULL) {
        printf("error while attempting to allocate rows for array.\n");
        
        return;
    }

    // loop and allocate rows for every pointer in the array
    for(int i = 0; i < rows; i++) {
        (* arr)[i] = (int *)malloc(cols * sizeof(int *));
        if ((*arr)[i] == NULL) {
            printf("error while attempting to allocate cols for array.\n");

            return;
        }
    }

}

int build_digit(char ** numloc) {
    int sign = 1;
    int value = 0;

    if (**numloc == '-') {
        sign = -1;
        (*numloc)++;
    }

    while (isdigit(**numloc)) {
        value = value * 10 + (**numloc - '0');
        (*numloc)++;
    }

    return sign * value;
}

void build_array(char *s, int *** arr) {
    char * crt_ptr = s;
    int row = 0, col = 0;

    while (*crt_ptr != '\0') {
        skip_whitespace(&crt_ptr);

        if (*crt_ptr == '[') {
            crt_ptr++;
            col = 0;
        } else if (*crt_ptr == ']') {
            crt_ptr++;
            row++;
        } else if (isdigit(*crt_ptr) || *crt_ptr == '-') {
            int val = build_digit(&crt_ptr);
            (*arr)[row][col++] = val;
        } else {
            crt_ptr++;
        }
    }
}
