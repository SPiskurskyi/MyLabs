#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


#define QUEUE_CAPACITY_Byte 11200
#define QUEUE_CAPACITY (QUEUE_CAPACITY_Byte / sizeof(float)) // 2800 елементів
// елемент черги
typedef struct QueueNode {
    float* data;
    struct QueueNode* next;
} QueueNode;
// черга
typedef struct {
    QueueNode* front;
    QueueNode* rear;
    size_t size; // фактичний розмір
    size_t capacity; // максимальний розмір
} Queue;
// створення черги
void createQueue(Queue** queue) {
    *queue = (Queue*)VirtualAlloc(NULL, QUEUE_CAPACITY_Byte, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (!(*queue)) {
        perror("Failed to allocate memory for the queue!\n");
        exit(EXIT_FAILURE);
    }
    (*queue)->front = NULL;
    (*queue)->rear = NULL;
    (*queue)->size = 0;
    (*queue)->capacity = QUEUE_CAPACITY;
}
// видалення черги
void destroyQueue(Queue* queue) {
    VirtualFree(queue, 0, MEM_RELEASE);
}
// перевірка чи черга порожня
int isEmpty(Queue* queue) {
    return queue->size == 0;
}
// додавання елемента в хвіст черги
void pushBack(Queue* queue, double value) {
    if (queue->size >= queue->capacity) {
        perror("Queue is full!\n");
        exit(EXIT_FAILURE);
    }
    QueueNode* newNode = (QueueNode*)VirtualAlloc(NULL, sizeof(QueueNode), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (!newNode) {
        perror("Failed to allocate memory for the new node!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = (double*)VirtualAlloc(NULL, sizeof(double), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (!(newNode->data)) {
        perror("Failed to allocate memory for the data!\n");
        exit(EXIT_FAILURE);
    }
    *(newNode->data) = value;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}
// видалення елемента з голови черги
void popFront(Queue* queue) {
    if (isEmpty(queue)) {
        perror("Queue is empty!\n");
        exit(EXIT_FAILURE);
    }
    QueueNode* temp = queue->front;
    queue->front = queue->front->next;
    VirtualFree(temp->data, 0, MEM_RELEASE);
    VirtualFree(temp, 0, MEM_RELEASE);
    queue->size--;
}
// перегляд елемента в голові черги
double getFront(Queue* queue) {
    if (isEmpty(queue)) {
        perror("Queue is empty!\n");
        exit(EXIT_FAILURE);
    }
    return *(queue->front->data);
}
// знайти найменший елемент черги
float FindMin(Queue* queue) {
    float minValue;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    QueueNode* current = queue->front;
    minValue = *(current->data);
    while (current != NULL) {
        if (*(current->data) < minValue)
            minValue = *(current->data);
        current = current->next;
    }
    return minValue;
}
int main() {
    Queue* queue;
    createQueue(&queue);
    pushBack(queue, -89.89);
    pushBack(queue, 89.89);
    pushBack(queue, 1.53);
    pushBack(queue, 33.33);
    pushBack(queue, -15.55);
    pushBack(queue, 105.501);
    popFront(queue);
    printf("First element of queue: %lf.\n\n", getFront(queue));
    printf("Min element of queue: %lf.\n\n", FindMin(queue));
    destroyQueue(queue);
    return 0;
}
