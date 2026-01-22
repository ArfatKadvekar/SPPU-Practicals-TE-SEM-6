#include <iostream>
#include <string>
using namespace std;

unsigned long hashFunction(string password) {
    unsigned long hash = 0;

    for (char c : password) {
        hash = hash * 31 + c; // hash = old_hash × 31 + ASCII_value
    }

    return hash;
}

int main() {
    string password;
    cout << "Enter password: ";
    cin >> password;

    unsigned long hashedPassword = hashFunction(password);

    cout << "Hashed value: " << hashedPassword << endl;
    return 0;
}
