#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_ITEMS 10
#define CYCLES 10

typedef struct my_queue {
    int * arr;
    size_t length;
    size_t max_length;
    pthread_mutex_t mutex;
} queue_t;

void initialize_queue(queue_t ** q, int maxlength);

void * produce(void * arg);
void * consume(void * arg);

pthread_cond_t not_empty, not_full;



int main(int argc, char ** argv) {

    queue_t * q;

    // for this example, we are going to populate the array with fibonacci numbers,
    // once the array is fully populated, the process will be paused, and the values will be consumed.
    initialize_queue(&q, MAX_ITEMS);

    pthread_t prod, cons;

    pthread_cond_init(&not_empty, NULL);
    pthread_cond_init(&not_full, NULL);

    pthread_create(&prod, NULL, produce, q);
    pthread_create(&cons, NULL, consume, q);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    pthread_mutex_destroy(&q->mutex);
    pthread_cond_destroy(&not_empty);
    pthread_cond_destroy(&not_full);
    free(q->arr);
    free(q);

    return 0;
}

void initialize_queue(queue_t ** q, int max_length) {
    *q = malloc(sizeof(queue_t));

    // initialize all the variables
    (*q)->arr = malloc(sizeof(int) * max_length);
    (*q)->length = 2;
    (*q)->max_length = max_length;
    pthread_mutex_init(&(*q)->mutex, NULL);

    // initialize the array with the digits for the
    (*q)->arr[0] = 1;
    (*q)->arr[1] = 1;
}

void * produce(void * arg){

    queue_t * q = (queue_t *)arg;

    for (int i = 0; i < CYCLES; i++) {
            // lock the queue
        pthread_mutex_lock(&q->mutex);
        while (q->length == q->max_length) {
            pthread_cond_wait(&not_full, &q->mutex);
        }

            int last = q->arr[q->length - 1];
            int sec_last = q->arr[q->length - 2];
            q->arr[q->length] = last + sec_last;

            printf("produced:\t%d\n", q->arr[q->length]);

            q->length++;

        
        pthread_cond_signal(&not_empty);
        //unlock the queue
        pthread_mutex_unlock(&q->mutex);
    }
    return NULL;
}

void * consume(void * arg) {

    queue_t * q = (queue_t *)arg;

    int consumed_value;
    
    for (int i = 0; i < CYCLES; i++) {    
        // lock the queue
        pthread_mutex_lock(&q->mutex);
        while (q->length <= 2) {
            pthread_cond_wait(&not_empty, &q->mutex);
        }

            consumed_value = q->arr[0];
            
            for (size_t i = 1; i < q->length; i++) {
                q->arr[i - 1] = q-> arr[i];
            }

            q->length--;

            printf("consumed:\t%d\n", consumed_value);

        pthread_cond_signal(&not_full);
        pthread_mutex_unlock(&q->mutex);
    }
    return NULL;
}
