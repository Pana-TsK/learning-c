#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define BUFFSIZE 64
#define SAMPLE_RATE 100
#define PI 3.14159265358979323846

size_t read_data(char * filename, double ** data_array, size_t buffsize);
size_t next_pow2(size_t n);
void fft(double complex * x, size_t N);
void print_fourier(const double complex * dft_output, size_t N);

int main(int argc, char ** argv) 
{
    double * data = NULL;
    size_t file_length = read_data("wave.txt", &data, BUFFSIZE);

    size_t N = next_pow2(file_length);

    // zero padded input
    double complex * x = calloc(N, sizeof(double complex));
    for (size_t i = 0; i < file_length; i++) {
        x[i] = data[i];  // imaginary part = 0
    }

    fft(x, N);
    print_fourier(x, N);

    free(data);
    free(x);
    return 0;
}

size_t next_pow2(size_t n) {
    size_t p = 1;
    while (p < n) p <<= 1;
    return p;
}

void fft(double complex * x, size_t N) {
    if (N <= 1) return;

    double complex * even = malloc((N/2) * sizeof(double complex));
    double complex * odd  = malloc((N/2) * sizeof(double complex));

    for (size_t i = 0; i < N/2; i++) {
        even[i] = x[2*i];
        odd[i]  = x[2*i + 1];
    }

    fft(even, N/2);
    fft(odd,  N/2);

    for (size_t k = 0; k < N/2; k++) {
        double complex t = cexp(-2.0 * I * PI * k / N) * odd[k];
        x[k]       = even[k] + t;
        x[k+N/2]   = even[k] - t;
    }

    free(even);
    free(odd);
}

size_t read_data(char * filename, double ** data_array, size_t buffsize)
{
    FILE * fptr = fopen(filename, "r");
    if (fptr == NULL) {
        perror("error reading file");
        exit(1);
    }

    *data_array = malloc(sizeof(double) * buffsize);
    if (*data_array == NULL) {
        perror("error allocating buffer");
        exit(1);
    }

    size_t count = 0;
    double temp_val;
    while (fscanf(fptr, "%lf", &temp_val) == 1) {
        if (count >= buffsize) {
            buffsize *= 2;
            double * temp_ptr = realloc(*data_array, sizeof(double) * buffsize);
            if (!temp_ptr) {
                perror("realloc failed");
                exit(1);
            }
            *data_array = temp_ptr;
        }
        (*data_array)[count++] = temp_val;
    }
    fclose(fptr);

    double * final_ptr = realloc(*data_array, sizeof(double) * count);
    if (final_ptr) *data_array = final_ptr;

    return count;
}

void print_fourier(const double complex * dft_output, size_t N)
{
    printf("Frequency (Hz)\tMagnitude\tPhase (rad)\n");
    printf("---------------------------------------------\n");

    for (size_t k = 0; k <= N/2; k++) {
        double freq = (double)k * SAMPLE_RATE / N;
        double magnitude = cabs(dft_output[k]) / N;  // normalize
        double phase = carg(dft_output[k]);
        printf("%.2f Hz\t\t%.6f\t%.6f\n", freq, magnitude, phase);
    }
}
