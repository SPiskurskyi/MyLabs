#include <iostream>
#include <openssl/evp.h>
#include <openssl/rand.h>

// Encrypt plaintext using AES in OFB mode with a statically initialized IV
void encryptAES(const unsigned char* plaintext, const unsigned char* key, unsigned char* ciphertext, size_t length) {
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        std::cerr << "Error creating context\n";
        return;
    }

    if (EVP_EncryptInit_ex(ctx, EVP_aes_192_ofb(), NULL, key, (unsigned char *)"SerhiiPiskursky") != 1) { // Initializing with static IV
        std::cerr << "Error initializing encryption\n";
        EVP_CIPHER_CTX_free(ctx);
        return;
    }

    int outlen;
    if (EVP_EncryptUpdate(ctx, ciphertext, &outlen, plaintext, length) != 1) {
        std::cerr << "Error encrypting data\n";
        EVP_CIPHER_CTX_free(ctx);
        return;
    }

    int final_len;
    if (EVP_EncryptFinal_ex(ctx, ciphertext + outlen, &final_len) != 1) {
        std::cerr << "Error finalizing encryption\n";
        EVP_CIPHER_CTX_free(ctx);
        return;
    }

    EVP_CIPHER_CTX_free(ctx);
}

// Decrypt ciphertext using AES in OFB mode with a statically initialized IV
void decryptAES(const unsigned char* ciphertext, const unsigned char* key, unsigned char* decryptedtext, size_t length) {
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        std::cerr << "Error creating context\n";
        return;
    }

    if (EVP_DecryptInit_ex(ctx, EVP_aes_192_ofb(), NULL, key, (unsigned char *)"SerhiiPiskursky") != 1) { // Initializing with static IV
        std::cerr << "Error initializing decryption\n";
        EVP_CIPHER_CTX_free(ctx);
        return;
    }

    int outlen;
    if (EVP_DecryptUpdate(ctx, decryptedtext, &outlen, ciphertext, length) != 1) {
        std::cerr << "Error decrypting data\n";
        EVP_CIPHER_CTX_free(ctx);
        return;
    }

    int final_len;
    if (EVP_DecryptFinal_ex(ctx, decryptedtext + outlen, &final_len) != 1) {
        std::cerr << "Error finalizing decryption\n";
        EVP_CIPHER_CTX_free(ctx);
        return;
    }

    EVP_CIPHER_CTX_free(ctx);
}

int main() {
    const unsigned char key[] = "PiskurskyiSerhiiVolodym"; // 192-bit key
    unsigned char plaintext[] = "Finally!! Last 8 lab is done!!!"; 
    unsigned char ciphertext[sizeof(plaintext)];
    unsigned char decryptedtext[sizeof(plaintext)];
    bool custom_text = 0;
    std::cout << "Do you want to enter you custom message(32 symbols) or use text by default(" << plaintext << ")? 0 - for no, any other for yes\n";
    std::cin >> custom_text;
    if(custom_text) {
        std::cout << "Enter message to be encrypted(Do not show this message anyone...)\n";
        scanf("%s",&plaintext); 
    }


    // Encrypt
    encryptAES(plaintext, key, ciphertext, sizeof(plaintext));
    std::cout << "Ciphertext: ";
    for (size_t i = 0; i < sizeof(plaintext); ++i) {
        std::cout << std::hex << (int)ciphertext[i];
    }
    std::cout << std::endl;

    // Decrypt
    decryptAES(ciphertext, key, decryptedtext, sizeof(ciphertext));
    std::cout << "Decrypted text: " << decryptedtext << std::endl;

    return 0;
}
