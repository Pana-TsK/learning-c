#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define M_PI 3.14159265359
#define SAMPLE_RATE 100.0

static size_t read_data(char * filename, double ** buffer);
static void print_array(double * buffer, size_t N);

int discrete_fourier_transform(double * data, double complex ** X, size_t bufflen);
void print_fourier(const double complex * dft_output, size_t N);

int main(int argc, char * argv[]) 
{
    double * data_buffer = NULL;
    size_t bufflen = read_data("wave.txt", &data_buffer);

    double complex * X = malloc(sizeof(double complex) * bufflen);
    discrete_fourier_transform(data_buffer, &X, bufflen);

    if(X != NULL) {
        print_fourier(X, bufflen);
    }

    free(X);
    free(data_buffer);
    return 0;
}

int discrete_fourier_transform(double * data, double complex ** X, size_t N)
{
    // loop over the input data
    for (int k = 0; k < N; k++) {
        // set the complex sum
        double complex sum = 0.0;

        for (int n = 0; n < N; n++) {
            double complex circle = cexp((-1 * I * 2 * M_PI * k * n) / N);
            sum += data[n] * circle;
        }
        (*X)[k] = sum;
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

void print_fourier(const double complex * dft_output, size_t N)
{
    printf("Frequency (Hz)\tMagnitude\tPhase (rad)\n");
    printf("---------------------------------------------\n");

    for (int k = 0; k <= N / 2; k++) {
        double freq = k * SAMPLE_RATE / N;
        double magnitude = cabs(dft_output[k]);
        double phase = carg(dft_output[k]);
        printf("%.2f Hz\t\t%.4f\t\t%.4f\n", freq, magnitude, phase);
    }
}

