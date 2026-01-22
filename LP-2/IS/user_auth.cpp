#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

unsigned long hashFunction(string password) {
    unsigned long hash = 0;
    for (char c : password)
        hash = hash * 31 + c;
    return hash;
}

string getMaskedPassword() {
    string password = "";
    char ch;

    while (true) {
        ch = _getch();

        if (ch == 13) 
            break;
        else if (ch == 8) { 
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b";
            }
        } else {
            password += ch;
            cout << "*";
        }
    }
    cout << endl;
    return password;
}

int main() {
    string storedUsername;
    unsigned long storedHash;

    // Registration Menu
    cout << "=== Registration ===\n";
    cout << "Create username: ";
    cin >> storedUsername;

    cout << "Create password: ";
    string regPass = getMaskedPassword();
    storedHash = hashFunction(regPass);

    cout << "\nUser registered successfully!\n\n";

    // Login Menu
    string inputUsername;
    cout << "=== Login ===\n";
    cout << "Enter username: ";
    cin >> inputUsername;

    cout << "Enter password: ";
    string loginPass = getMaskedPassword();

    if (inputUsername == storedUsername &&
        hashFunction(loginPass) == storedHash) {

        cout << "\nAuthentication Successful. Welcome, "
             << inputUsername << "!\n";
    } else {
        cout << "\nAuthentication Failed. Invalid credentials.\n";
    }

    return 0;
}
