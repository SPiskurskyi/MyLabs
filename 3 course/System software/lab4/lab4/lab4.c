#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void getAccessTime(const char* FileName) {
    WIN32_FILE_ATTRIBUTE_DATA fileData;
    if (GetFileAttributesExA(FileName, GetFileExInfoStandard, &fileData)) {
        FILETIME AccessTime = fileData.ftLastAccessTime;
        SYSTEMTIME systemTime;
        FileTimeToSystemTime(&AccessTime, &systemTime);
        printf("Last accesisng file '%s': %02d/%02d/%d %02d:%02d:%02d\n", FileName,
            systemTime.wDay, systemTime.wMonth, systemTime.wYear,
            systemTime.wHour, systemTime.wMinute, systemTime.wSecond);
    }
    else {
        printf("Error getting last accessing time of directory '%s'. Error code: %d\n", FileName, GetLastError());
    }
}

void deleteFile(LPCWSTR FileName) {
    if (!DeleteFile(FileName)) {
        printf("Delete file failed. \n");
    } else {
        printf("File was successfully deleted. \n");
    }
}

void checkDirectoryForReading(const char* Directory) {
    DWORD attributes = GetFileAttributesA(Directory);
    if (attributes != INVALID_FILE_ATTRIBUTES) {
        if (attributes & FILE_ATTRIBUTE_READONLY) {
            printf("Directory %s attributes:\n\tRead-only: Yes\n", Directory);
        }
        else {
            printf("Directory %s attributes:\n\tRead-only: No\n", Directory);
        }
    } else {
        printf("Error getting file attributes for '%s'. Error code: %d\n", Directory, GetLastError());
    }

}

int main() {
    LPCWSTR delFile = L"test.txt";
    const char* accessFile = "lab4.c";
    const char* checkDirectory = "C:\\Windows\\System32";

    deleteFile(delFile);
    getAccessTime(accessFile);
    checkDirectoryForReading(checkDirectory);

    return 0;
}