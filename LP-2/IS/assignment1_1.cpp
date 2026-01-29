#include <iostream>
#include <string>
using namespace std;

int main() {
    string msg = "Hello World";
    int shift = 3;

    for (int i = 0; i < msg.length(); i++) {
        char ch = msg[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + shift) % 26 + 'a';
        }
        else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A';
        }

        msg[i] = ch;
    }

    cout << "Encrypted Message: " << msg << endl;

    return 0;
}
