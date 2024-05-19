#include <iostream>
#include <vector>

using namespace std;

// Function to transform a subblock with a key (XOR)
int f(int subblock, unsigned int key) {
    return subblock ^ key;
}

// Encryption of the plaintext
void crypt(int& message, int rounds, const vector<unsigned int>& key) {
    int left = message >> 16; // Extract left part
    int right = message & 0xFFFF; // Extract right part

    int temp;
    for (int i = 0; i < rounds; i++) {
        temp = right ^ f(left, key[i]);
        right = left;
        left = temp;
    }

    // Combine left and right parts back into message
    message = (left << 16) | (right & 0xFFFF); // Mask the right part
}

// Decryption of the ciphertext
void decrypt(int& message, int rounds, const vector<unsigned int>& key) {
    int left = message >> 16; // Extract left part
    int right = message & 0xFFFF; // Extract right part

    int temp;
    for (int i = rounds - 1; i >= 0; i--) {
        temp = left ^ f(right, key[i]);
        left = right;
        right = temp;
    }

    // Combine left and right parts back into message
    message = (left << 16) | (right & 0xFFFF); // Mask the right part
}

int main() {
    const int rounds = 4;
    int message = 0x89ABCDEF;
    vector<unsigned int> key = { 15, 1, 15, 0 };

    crypt(message, rounds, key);
    cout << "Encrypted: Message=" << hex << message << endl;

    decrypt(message, rounds, key);
    cout << "Decrypted: Message=" << hex << message << endl;

    return 0;
}
