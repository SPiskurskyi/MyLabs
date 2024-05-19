#include<iostream>
#include<math.h>

using namespace std;                   //  P   I   S   K   U   R   S   K   Y
                                       //  80, 73, 83, 75, 85, 82, 83, 75, 89
float encrypt_v[3][1], decrypt_v[3][1], message_v[3][1];                                         // VECTORS
float inverse_m[3][3], primary_m[3][3] = { 80, 73, 83, 75, 85, 82, 83, 75, 89 }, helper_m[3][3]; // MATRIXES

void getKeyMatrix() {
    int i, j;
    char mes[4];
    srand(time(NULL));
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            helper_m[i][j] = primary_m[i][j];
        }
    cout << "\nEnter message to be encrypted (3 UPPER CASE CHARS)\n";
    cin >> mes;

    for (i = 0; i < 3; i++)
        message_v[i][0] = mes[i] - 65;;

    cout << "\nKey Matrix is:\n";
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            cout << primary_m[i][j] << " ";
        cout << "\n";
    }
}
void encrypt() {
    int i, j, k;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 1; j++)
            for (k = 0; k < 3; k++)
                encrypt_v[i][j] = encrypt_v[i][j] + primary_m[i][k] * message_v[k][j];
    cout << "\nEncrypted message: ";
    for (i = 0; i < 3; i++)                                                          // mask symbols
        cout << (char)(fmod(encrypt_v[i][0], 26) + 65) << (char)('A' + rand() % 26); // {v, m, v} variant 15
    cout << endl;
}
void inversematrix() {
    int i, j, k;
    float p, q;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            if (i == j)
                inverse_m[i][j] = 1;
            else
                inverse_m[i][j] = 0;
        }
    for (k = 0; k < 3; k++) {
        for (i = 0; i < 3; i++) {
            p = helper_m[i][k];
            q = helper_m[k][k];
            for (j = 0; j < 3; j++) {
                if (i != k) {
                    helper_m[i][j] = helper_m[i][j] * q - p * helper_m[k][j];
                    inverse_m[i][j] = inverse_m[i][j] * q - p * inverse_m[k][j];
                }
            }
        }
    }
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            inverse_m[i][j] = inverse_m[i][j] / helper_m[i][i];
    cout << "\nInverse Matrix is:\n";
    cout.precision(2);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            cout <<  inverse_m[i][j] << " ";
        cout << "\n";
    }
}
void decrypt() {
    int i, j, k;
    inversematrix();
    for (i = 0; i < 3; i++)
        for (j = 0; j < 1; j++)
            for (k = 0; k < 3; k++)
                decrypt_v[i][j] = decrypt_v[i][j] + inverse_m[i][k] * encrypt_v[k][j];
    cout << "\nDecrypted message: ";
    for (i = 0; i < 3; i++)
        cout << (char)(fmod(decrypt_v[i][0], 26) + 65);
    cout << "\n";
}
int main() {
    getKeyMatrix();
    encrypt();
    decrypt();
}
