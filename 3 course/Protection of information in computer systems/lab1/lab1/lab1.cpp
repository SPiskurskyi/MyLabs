#include <iostream>
#include <string>
#include <locale>

#ifdef _WIN32
#include <io.h> 
#include <fcntl.h> 
#else
#include <cwchar>
#endif


using namespace std;

wstring encryptCaesarCipher(const wstring& input, int step) {
    wstring result = L"";
    for (wchar_t c : input) {
        if (iswalpha(c)) {
            wchar_t base = (iswupper(c)) ? L'�' : L'�';
            result += wchar_t((c - base + step + 32) % 32 + base);
        }
        else {
            result += c; 
        }
    }
    return result;
}

int main() {
#ifdef _WIN32
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
#endif
    setlocale(LC_ALL, "");

    wstring message;
    int shift;

    wcout << L"������ ���� ����������� ���������: ";
    getline(wcin, message);

    wcout << L"������ ���� (������� ���� �����): ";
    wcin >> shift;

    wstring encryptedMessage = encryptCaesarCipher(message, shift);
    wcout << L"����������� �����������: " << encryptedMessage << endl;

    return 0;
}