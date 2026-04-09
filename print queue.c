#include <stdio.h>
#include <string.h>

#define MAX 100
#define NAME_LEN 50

typedef struct {
    char jobName[NAME_LEN];
    int pages;
} PrintJob;

typedef struct {
    PrintJob jobs[MAX];
    int front, rear;
} Queue;

// Initialize queue
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

// Check empty
int isEmpty(Queue *q) {
    return q->rear < q->front;
}

// Check full
int isFull(Queue *q) {
    return q->rear >= MAX - 1;
}

// Enqueue
void enqueue(Queue *q, char *name, int pages) {
    if (isFull(q)) {
        printf("Queue is full. Cannot add job.\n");
        return;
    }
    q->rear++;
    strcpy(q->jobs[q->rear].jobName, name);
    q->jobs[q->rear].pages = pages;
    printf("Job '%s' added to queue.\n", name);
}

// Dequeue (process job)
void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. No job to process.\n");
        return;
    }
    PrintJob job = q->jobs[q->front];
    printf("Processing job '%s' with %d pages.\n", job.jobName, job.pages);
    q->front++;
}

// Peek next job
void peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    PrintJob job = q->jobs[q->front];
    printf("Next job: '%s' (%d pages)\n", job.jobName, job.pages);
}

// Display all jobs in queue
void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Print Queue:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d. '%s' (%d pages)\n", i - q->front + 1, q->jobs[i].jobName, q->jobs[i].pages);
    }
    printf("\n");
}

// Main
int main() {
    Queue printerQueue;
    initQueue(&printerQueue);

    enqueue(&printerQueue, "Document1", 5);
    enqueue(&printerQueue, "Document2", 2);
    enqueue(&printerQueue, "Report", 10);

    displayQueue(&printerQueue);

    peek(&printerQueue);

    dequeue(&printerQueue);
    dequeue(&printerQueue);

    displayQueue(&printerQueue);

    enqueue(&printerQueue, "Invoice", 3);
    displayQueue(&printerQueue);

    return 0;
}
