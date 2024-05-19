#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using std::string;
using std::cout;
using std::endl;

string readEncrypted(const string& path, int shift);
int decrypt(const string& encrypted);

int main() {
    string path = "message.txt";
    string message;
    int shift = 15;
    
    message = readEncrypted(path, shift);
    cout << message << endl;
    cout << "Shift which was used for encryption is - " << decrypt(message) << endl;

    return 0;
}

string readEncrypted(const string& path, int shift) {
    std::ifstream file;
    file.open(path);
    if (!file.is_open()) {
        std::cerr << "Error opening file." << endl;
        abort();
    }
    string raw((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    string encrypted = "";

    for (int i = 0; i < raw.size(); i++) {
        if (std::isalpha(raw[i])) {
            if (isupper(raw[i]))
                encrypted += char(int(raw[i] + shift - 65) % 26 + 65);

            else
                encrypted += char(int(raw[i] + shift - 97) % 26 + 97);
        }
        else {
            encrypted += raw[i];
        }
    }
    return encrypted;
}

int decrypt(const string& encrypted)
{
    float perc[26] = { 0 };
    int freq = 0;
    float maxPerc = 0;
    int maxInx = 0;

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < encrypted.size(); j++)
        {
            if (encrypted[j] == char('a' + i))
            {
                freq++;
            }
        }
        perc[i] = (float)freq / encrypted.size() * 100;
        freq = 0;
        cout << "letter " << char('a' + i) << " percent - " << std::setprecision(2) << perc[i] << "%" << std::endl;
        if (perc[i] > maxPerc) {
            maxPerc = perc[i];
            maxInx = i;
        }
    }

    int shift = (('a' + maxInx) - 'e');
    return shift;

}
