#include <iostream>
#include <string>
#include <windows.h>  

using namespace std;

int main() {
    string correctPassword = "admin123";
    string input;
    int attempts = 0;

    while (true) {
        cout << "Enter password: ";
        cin >> input;

        if (input == correctPassword) {
            cout << "Login Successful\n";
            break;
        } else {
            attempts++;
            cout << "Wrong password\n";
        }

        if (attempts == 3) {
            cout << "\nAccount locked. Try again after 30 seconds.\n";

            for (int i = 30; i > 0; i--) {
                cout << "\rRetry in " << i << " seconds...";
                cout.flush();
                Sleep(1000); // 1 second
            }

            cout << "\nYou can try again now.\n\n";
            attempts = 0;
        }
    }
    return 0;
}
