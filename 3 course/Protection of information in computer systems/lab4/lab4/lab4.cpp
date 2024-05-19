#include <iostream>
#include <fstream>
#include <cstdint>
#include <vector>

using namespace std;

const int HEADER_SIZE = 54; // BMP header size

// Function to hide a message within the least significant bits of the pixel data
void hideMessage(const string& inputFile, const string& outputFile, const string& message) {
    ifstream fin(inputFile, ios::binary);
    ofstream fout(outputFile, ios::binary);

    if (!fin.is_open()) {
        cerr << "Error: Could not open input file." << endl;
        return;
    }

    if (!fout.is_open()) {
        cerr << "Error: Could not create output file." << endl;
        fin.close();
        return;
    }

    // Read BMP header
    char header[HEADER_SIZE];
    fin.read(header, HEADER_SIZE);
    fout.write(header, HEADER_SIZE);

    // Calculate message length
    uint32_t messageLength = message.length();

    // Write message length to the first 4 bytes after the header
    fout.write(reinterpret_cast<const char*>(&messageLength), sizeof(uint32_t));

    // Convert the message to binary
    vector<bool> messageBits;
    for (char c : message) {
        for (int i = 7; i >= 0; --i) {
            messageBits.push_back((c >> i) & 1);
        }
    }

    // Hide the message in the LSBs of the pixel data
    char pixelData;
    size_t bitIndex = 0;
    while (fin.get(pixelData)) {
        if (bitIndex < messageBits.size()) {
            // Modify the least significant bit of the pixel data
            pixelData &= 0xFE; // Clear the least significant bit
            pixelData |= messageBits[bitIndex]; // Set the least significant bit to the next message bit
            ++bitIndex;
        }
        fout.put(pixelData);
    }

    fin.close();
    fout.close();

    cout << "Message hidden successfully." << endl;
}

// Function to read a hidden message from the least significant bits of the pixel data
void readMessage(const string& inputFile) {
    ifstream fin(inputFile, ios::binary);

    if (!fin.is_open()) {
        cerr << "Error: Could not open input file." << endl;
        return;
    }

    // Skip BMP header
    fin.seekg(HEADER_SIZE, ios::beg);

    // Read message length from the first 4 bytes after the header
    uint32_t messageLength;
    fin.read(reinterpret_cast<char*>(&messageLength), sizeof(uint32_t));

    // Read message bits from the LSBs of the pixel data
    string message;
    char pixelData;
    size_t bitIndex = 0;
    char currentByte = 0;
    while (bitIndex < messageLength * 8 && fin.get(pixelData)) {
        // Extract the least significant bit of the pixel data
        char bit = pixelData & 1;
        currentByte |= (bit << (7 - (bitIndex % 8)));
        ++bitIndex;
        if (bitIndex % 8 == 0) {
            message.push_back(currentByte);
            currentByte = 0;
        }
    }

    fin.close();

    // Output the hidden message
    cout << "Hidden message: " << message << endl;
}

int main() {
    string inputFile = "test.bmp";
    string outputFile = "output.bmp";
    string message = "Hello, world!";

    // Hide the message in the image
    hideMessage(inputFile, outputFile, message);

    // Read the hidden message from the modified image
    readMessage(outputFile);

    return 0;
}
