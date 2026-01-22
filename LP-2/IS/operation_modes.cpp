#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

const int BLOCK_SIZE = 8;

/* ---------------- Toy Block Cipher (XOR) ---------------- */
vector<char> encryptBlock(vector<char> block, string key) {
    for (int i = 0; i < BLOCK_SIZE; i++)
        block[i] ^= key[i % key.size()];
    return block;
}

/* ---------------- ECB ---------------- */
vector<char> ECB(vector<char> data, string key) {
    vector<char> out;
    for (int i = 0; i < data.size(); i += BLOCK_SIZE) {
        vector<char> block(data.begin()+i, data.begin()+i+BLOCK_SIZE);
        block = encryptBlock(block, key);
        out.insert(out.end(), block.begin(), block.end());
    }
    return out;
}

/* ---------------- CBC ---------------- */
vector<char> CBC(vector<char> data, string key, vector<char> iv) {
    vector<char> out, prev = iv;

    for (int i = 0; i < data.size(); i += BLOCK_SIZE) {
        vector<char> block(data.begin()+i, data.begin()+i+BLOCK_SIZE);
        for (int j = 0; j < BLOCK_SIZE; j++)
            block[j] ^= prev[j];

        block = encryptBlock(block, key);
        prev = block;
        out.insert(out.end(), block.begin(), block.end());
    }
    return out;
}

/* ---------------- CFB ---------------- */
vector<char> CFB(vector<char> data, string key, vector<char> iv) {
    vector<char> out, prev = iv;

    for (int i = 0; i < data.size(); i += BLOCK_SIZE) {
        vector<char> keystream = encryptBlock(prev, key);
        vector<char> block(data.begin()+i, data.begin()+i+BLOCK_SIZE);

        for (int j = 0; j < BLOCK_SIZE; j++)
            block[j] ^= keystream[j];

        prev = block;
        out.insert(out.end(), block.begin(), block.end());
    }
    return out;
}

/* ---------------- OFB ---------------- */
vector<char> OFB(vector<char> data, string key, vector<char> iv) {
    vector<char> out;
    vector<char> stream = iv;

    for (int i = 0; i < data.size(); i += BLOCK_SIZE) {
        stream = encryptBlock(stream, key);
        vector<char> block(data.begin()+i, data.begin()+i+BLOCK_SIZE);

        for (int j = 0; j < BLOCK_SIZE; j++)
            block[j] ^= stream[j];

        out.insert(out.end(), block.begin(), block.end());
    }
    return out;
}

/* ---------------- CTR ---------------- */
vector<char> CTR(vector<char> data, string key, vector<char> nonce) {
    vector<char> out;
    vector<char> counter = nonce;

    for (int i = 0; i < data.size(); i += BLOCK_SIZE) {
        vector<char> keystream = encryptBlock(counter, key);
        vector<char> block(data.begin()+i, data.begin()+i+BLOCK_SIZE);

        for (int j = 0; j < BLOCK_SIZE; j++)
            block[j] ^= keystream[j];

        counter[BLOCK_SIZE - 1]++; // increment counter
        out.insert(out.end(), block.begin(), block.end());
    }
    return out;
}

/* ---------------- Print Utility ---------------- */
void printCipher(string name, vector<char> data) {
    cout << name << ": ";
    for (char c : data)
        cout << hex << setw(2) << setfill('0') << (int)(unsigned char)c << " ";
    cout << endl;
}

/* ---------------- MAIN ---------------- */
int main() {
    string key = "secret";
    string plaintext = "HELLOWORLD12345"; // 16 bytes
    vector<char> data(plaintext.begin(), plaintext.end());

    vector<char> iv(BLOCK_SIZE, 'I');
    vector<char> nonce(BLOCK_SIZE, 'N');

    printCipher("ECB", ECB(data, key));
    printCipher("CBC", CBC(data, key, iv));
    printCipher("CFB", CFB(data, key, iv));
    printCipher("OFB", OFB(data, key, iv));
    printCipher("CTR", CTR(data, key, nonce));

    return 0;
}
