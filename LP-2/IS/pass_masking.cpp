#include <iostream>
#include <conio.h>  
using namespace std;

int main() {
    string password = "";
    char ch;

    cout << "Enter password: ";

    while (true) {
        ch = _getch();     

        if (ch == 13) {  
            break;
        }
        else if (ch == 8) { 
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b";
            }
        }
        else {
            password += ch;
            cout << "*";
        }
    }

    cout << "\nPassword stored successfully.\n";
    return 0;
}
