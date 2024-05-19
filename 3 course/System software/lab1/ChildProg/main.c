#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>

struct ThreadArgs {
    int* array; 
    int array_size; 
};

DWORD WINAPI findMin(LPVOID lpParam) {
    struct ThreadArgs* threadArgs = (struct ThreadArgs*)lpParam;
    int* array = threadArgs->array;
    int size = threadArgs->array_size;
    int min = INT_MAX; 
    for (int i = 0; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}


int main() {
    srand(time(NULL));
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int* array = (int*)malloc(size * sizeof(int));

    if (array == NULL)
        return 1;

    printf("Auto generated array:\n");
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
        printf("%d ", array[i]);
    }
    printf("\n");

    struct ThreadArgs threadArgs;
    threadArgs.array = array;
    threadArgs.array_size = size;
    HANDLE hThread;
    DWORD dwThreadId;

    hThread = CreateThread(
        NULL, // default security attributes
        0, // use default stack size
        findMin, // thread function
        &threadArgs, // argument to thread function
        0, // use default creation flags
        &dwThreadId); // returns the thread identifier
    if (hThread == NULL) {
        fprintf(stderr, "Error creating thread (%lu).\n", GetLastError());
        return 1;
    }

    WaitForSingleObject(hThread, INFINITE);

    DWORD exitCode;
    GetExitCodeThread(hThread, &exitCode);
    printf("\nMin number: %d\n", (int)exitCode);
    printf("\n");

    printf("\nThread ID: %lu\n", dwThreadId);
    printf("Thread Handle: %p\n\n", hThread);
    printf("Main process ID: %lu\n", GetCurrentProcessId());
    printf("Main thread ID: %lu\n", GetCurrentThreadId());
    printf("Main process Handle: %p\n", GetCurrentProcess());
    printf("Main thread Handle: %p\n", GetCurrentThread());
    
    system("pause"); // for no immediate close console
    CloseHandle(hThread);
    free(array);
    return 0;
}
