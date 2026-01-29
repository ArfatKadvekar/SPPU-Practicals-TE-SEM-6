#include <iostream>
#include <string>
using namespace std;

int main() {
    string msg = "Hello World";
    int key = 127;

    cout << "Char\tASCII\tAND\tXOR\n";
    cout << "---------------------------\n";

    for (int i = 0; i < msg.length(); i++) {
        char original = msg[i];
        char andResult = original & key;
        char xorResult = original ^ key;

        cout << original << "\t"
             << int(original) << "\t"
             << int(andResult) << "\t"
             << int(xorResult) << endl;
    }

    return 0;
}