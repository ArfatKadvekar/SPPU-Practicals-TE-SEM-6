#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int correctPIN;
    cout << "Enter 4-digit PIN: ";
    cin >> correctPIN;

    int attempts = 0;

    for (int guess = 0; guess <= 9999; guess++) {
        attempts++;
        
        cout << "\rTrying: "
             << setw(4) << setfill('0') << guess
             << " | Attempts: " << attempts;
        cout.flush();

        if (guess == correctPIN) {
            cout << "\n\nPIN cracked successfully!\n";
            cout << "Total attempts required: "
                 << attempts << endl;
            break;
        }
    }

    return 0;
}
