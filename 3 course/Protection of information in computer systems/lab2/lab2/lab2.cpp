#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

// Function to encrypt plaintext using permutation cipher
std::string encrypt(const std::string& plaintext, const std::vector<int>& permutation) {
    std::string ciphertext = "";
    int cols = permutation.size();
    int rows = (plaintext.length() + cols - 1) / cols;
    std::vector<std::vector<char>> matrix(rows, std::vector<char>(cols, ' '));

    int k = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (k < plaintext.length()) {
                matrix[i][j] = plaintext[k++];
            }
        }
    }

    for (int j = 0; j < cols; ++j) {
        int perm_index = permutation[j];
        for (int i = 0; i < rows; ++i) {
            ciphertext += matrix[i][perm_index];
        }
    }

    return ciphertext;
}

// Function to decrypt ciphertext using permutation cipher
std::string decrypt(const std::string& ciphertext, const std::vector<int>& permutation) {
    std::string plaintext = "";
    int cols = permutation.size();
    int rows = (ciphertext.length() + cols - 1) / cols;
    std::vector<std::vector<char>> matrix(rows, std::vector<char>(cols, ' '));

    // Create the matrix by putting the ciphertext characters in appropriate positions
    int k = 0;
    for (int j = 0; j < cols; ++j) {
        int perm_index = permutation[j];
        for (int i = 0; i < rows; ++i) {
            if (k < ciphertext.length()) {
                matrix[i][perm_index] = ciphertext[k++];
            }
        }
    }

    // Read the plaintext from the matrix
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            plaintext += matrix[i][j];
        }
    }

    return plaintext;
}

int main() {
    std::string plaintext, ciphertext;
    std::vector<int> permutation;

    // Input plaintext
    std::cout << "Enter plaintext: ";
    std::getline(std::cin, plaintext);

    // Input permutation
    std::cout << "Enter permutation (e.g., 1 0 2 for a 3-column matrix): ";
    std::string perm_str;
    std::getline(std::cin, perm_str);
    std::stringstream ss(perm_str);
    int val;
    while (ss >> val) {
        permutation.push_back(val);
    }

    // Encrypt the plaintext
    ciphertext = encrypt(plaintext, permutation);
    std::cout << "Encrypted ciphertext: " << ciphertext << std::endl;

    // Decrypt the ciphertext
    std::string decrypted_text = decrypt(ciphertext, permutation);
    std::cout << "Decrypted plaintext: " << decrypted_text << std::endl;

    return 0;
}
