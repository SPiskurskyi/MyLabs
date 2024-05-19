#pragma comment(lib, "Ws2_32.lib")
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <winsock2.h>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <stdlib.h> // Для функції rand()
#include <time.h> // Для функції srand()
int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    printf("TCP Сервер \n");
    printf("___________\n\n");
    WSADATA wsaData;
    SOCKET ListeningSocket;
    SOCKET NewConnection;
    struct sockaddr_in ServerAddr;
    struct sockaddr_in ClientAddr;
    int ClientAddrLen;

    u_short Port = 5150;
    int Ret;
    char DataBuffer[10024];
    char msg[10024];
    // Ініціалізація Winsock версії 2.2
    if ((Ret = WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0)
    {
        //Winsock не завантажився. Код помилки повертає функция WSAStartup
        printf("Помилка WSAStartup, номер помилки %d\n", Ret);
        return -1;
    }
    // Створимо новий TCP сокет для для прийому запитів на з'єднання від клієнтів.
    if ((ListeningSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
    {
        printf("Помилка socket, номер помилки %d\n", WSAGetLastError());
        WSACleanup();
        return -2;
    }
    // Заповнюємо struct sockaddr_in ServerAddr, яка скаже функції
    //bind, що ми хочемо слухати з'єднання на всіх інтерфейсах
    //(INADDR_ANY), використовуючи порт 5150.
    // Ми перетворюємо порядок байтів з системного у мережний (htons та htonl)
    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(Port);
    ServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1");//htonl(INADDR_ANY);
    // Функція bind прив'язує адресну інформацію, визначену в ServerAddr до сокету ListeningSocket
    if (bind(ListeningSocket, (struct sockaddr*)&ServerAddr, sizeof(ServerAddr)) == SOCKET_ERROR)
    {
        printf("Помилка bind, номер помилки %d\n", WSAGetLastError());
        closesocket(ListeningSocket);
        WSACleanup();
        return -3;
    }
    // Робимо сокет пасивним для прослуховування (прийому) запитів на TCP-з'єднання від клієнтів. Довжина черги запитів на
        //з'єднання дорівнює 5
     if (listen(ListeningSocket, 5) == SOCKET_ERROR)
     {
        printf("Помилка listen, номер помилки %d\n", WSAGetLastError());
        closesocket(ListeningSocket);
        WSACleanup();
        return -4;
     }
    printf("Сервер прослуховує на IP: %s\n", inet_ntoa(ServerAddr.sin_addr));
    printf("Чекаємо з'єднання на порту %d.\n", Port);
    ClientAddrLen = sizeof(ClientAddr);
    // Приймаємо нове з'єднання, коли воно виникне
    if ((NewConnection = accept(ListeningSocket, (struct sockaddr*)&ClientAddr, &ClientAddrLen)) == INVALID_SOCKET)
    {
        printf("Помилка accept, номер помилки %d\n", WSAGetLastError());
        closesocket(ListeningSocket);
        WSACleanup();
        return -5;
    }
    printf("Успішно з'єдналися з %s:%d.\n", inet_ntoa(ClientAddr.sin_addr), ntohs(ClientAddr.sin_port));
    // Далі ми можемо знову очікувати на сокеті ListeningSocket
    //нові з'єднання знову, викликаючи accept та/або почати
    //передавати та приймати дані на сокеті NewConnection.
    // Для простоти зупинимо прослуховування, закриваючи сокет
    //ListeningSocket. Можна починати прийом та передачу даних на
    //сокеті NewConnection.
    closesocket(ListeningSocket);
    printf("Чекаємо дані для отримання...\n");
    if ((Ret = recv(NewConnection, DataBuffer, sizeof(DataBuffer), 0)) == SOCKET_ERROR)
    {
        printf("Помилка recv, номер помилки %d\n", WSAGetLastError());
        closesocket(NewConnection);
        WSACleanup();
        return -6;
    }
    // Створюємо з отриманих даних рядок мови С
    if (Ret <= 1024)
        DataBuffer[Ret] = '\0';
    else
    {
        printf("Повідомлення задовге!\n");
        return -7;
    }
    DataBuffer[Ret] = '\0';
    printf("Успішно отримано %d байтів в повідомленні \"%s\".\n", Ret, DataBuffer);
    // Генеруємо масив випадкових чисел заданого розміру
    srand(time(NULL)); // Ініціалізуємо генератор випадкових чисел
    int arraySize = atoi(DataBuffer); // Розмір масиву
    int* Array = (int*)malloc(arraySize * sizeof(int)); // Виділяємо пам'ять для масиву
    if (Array == NULL) {
        printf("Не вдалося виділити пам'ять для масиву.\n");
        closesocket(NewConnection);
        WSACleanup();
        return -9;
    }
    int zeroCount = 0;
    printf("Масив:\n");
    for (int i = 0; i < arraySize; i++) {
        Array[i] = rand() % 100;
        printf("%d ", Array[i]);
    }
    int minEl = Array[0];
    for (int i = 0; i < arraySize; i++) {
        if (Array[i] < minEl) {
            minEl = Array[i];
        }
    }
    printf("\n");
    char message[1024];
    sprintf(message, "Наменше число в масиві: %d", minEl);
    if ((Ret = send(NewConnection, message, strlen(message), 0)) == SOCKET_ERROR)
    {
        printf("Помилка send, номер помилки %d\n", WSAGetLastError());
        closesocket(NewConnection);
        WSACleanup();
        return -8;
    }
    printf("Успішно передано %d байт повідомлення \"%s\".\n", Ret, message);
    printf("Закриваємо з'єднання з клієнтом.\n");
    closesocket(NewConnection);
    // Вивантажуємо Winsock
    WSACleanup();
    printf("Натисніть Enter для завершення.\n");
    getchar();
    free(Array); // Звільняємо пам'ять, виділену для масиву
    return 0;
}