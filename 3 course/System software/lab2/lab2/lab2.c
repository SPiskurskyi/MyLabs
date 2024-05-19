#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct ThreadArgs {
    int* array; // Масив
    int array_size; // Розмір масиву
};

// Функція потоку для пошуку найменшого елементу
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
    scanf_s("%d", &size);
    
    int* array = (int*)malloc(size * sizeof(int));

    if (array == NULL)
        return 1;

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000000;
    }
    // Отримання дескриптора поточного процесу
    HANDLE hProcess = GetCurrentProcess();
    // Отримання пріоритету класу для поточного процесу
    int priorityClass = GetPriorityClass(hProcess);
    printf("Priority class for the current process: %d\n", priorityClass);

    // Створення структури з аргументами для функції потоку
    struct ThreadArgs threadArgs;
    threadArgs.array = array;
    threadArgs.array_size = size;
    HANDLE hThread;
    DWORD dwThreadId;
    // Послідовно запускаємо потік з різними рівнями пріоритету
    for (int priority = THREAD_PRIORITY_IDLE; priority <= THREAD_PRIORITY_TIME_CRITICAL;
        priority += 10) {
        // Створення потоку з вказаним рівнем пріоритету
        hThread = CreateThread(
            NULL, // default security attributes
            0, // use default stack size
            findMin, // thread function
            &threadArgs, // argument to thread function
            CREATE_SUSPENDED, // create suspended initially
            &dwThreadId); // returns the thread identifier
        if (hThread == NULL) {
            fprintf(stderr, "Error creating thread (%lu).\n", GetLastError());
            return 1;
        }
        // Задання рівня пріоритету потоку
        SetThreadPriority(hThread, priority);
        // Пускаємо потік у виконання
        ResumeThread(hThread);
        // Чекаємо завершення потоку
        WaitForSingleObject(hThread, INFINITE);
        // Виведення обернутого масиву
        printf("-----------------------------------------------\n");
        printf("Array with priority %d:\n", priority);
        DWORD exitCode;
        GetExitCodeThread(hThread, &exitCode);
        // Визначення часу виконання потоку за допомогою GetThreadTimes()
        FILETIME creationTime, exitTime, kernelTime, userTime;
        if (GetThreadTimes(hThread, &creationTime, &exitTime, &kernelTime, &userTime)) {
            ULARGE_INTEGER kernelTimeInt, userTimeInt;
            kernelTimeInt.LowPart = kernelTime.dwLowDateTime;
            kernelTimeInt.HighPart = kernelTime.dwHighDateTime;
            userTimeInt.LowPart = userTime.dwLowDateTime;
            userTimeInt.HighPart = userTime.dwHighDateTime;
            printf("\nKernel Time: %.20f milliseconds\n", kernelTimeInt.QuadPart * 1e4);
            printf("User Time: %.20f milliseconds\n", userTimeInt.QuadPart * 1e-4);
            SYSTEMTIME systemTime;
            FileTimeToSystemTime(&creationTime, &systemTime); 
            printf("\nThread start time: %u:%u:%u:%u\n", systemTime.wHour,
            systemTime.wMinute, systemTime.wSecond, systemTime.wMilliseconds);
            FileTimeToSystemTime(&exitTime, &systemTime); 
            printf("Thread end time: %u:%u:%u:%u\n", systemTime.wHour,
            systemTime.wMinute, systemTime.wSecond, systemTime.wMilliseconds);
            ULONGLONG ThreadCycleTime;
            QueryThreadCycleTime(hThread, &ThreadCycleTime);
            printf("\nThread execution time : %llu tacts\n", ThreadCycleTime);
        }
        // Закриття дескрипторів, які більше не потрібні
        CloseHandle(hThread);
    }
    return 0;
}
