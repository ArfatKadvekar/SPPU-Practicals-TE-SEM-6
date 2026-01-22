#include<iostream>
using namespace std;

int main() {
    bool hasUpper = false, haslower = false, hasdigit = false, hasSymbol = false;
    string password;
    cout << "Enter passowrd : ";
    cin >> password;

    if(password.length() < 8){
        cout << "\033[43m The password is Weak length is below \033[0m" << endl;
        return 0;
    }
    for(char c : password){
        if(isupper(c)) hasUpper = true;
        else if(islower(c)) haslower = true;
        else if(isdigit(c)) hasdigit = true;
        else hasSymbol = true;
    }
    if (hasUpper && haslower && hasdigit && hasSymbol)
        cout << "\033[42m Strong Password \033[0m\n";
    else
        cout << "\033[41m Weak Password\n \033[0m";
    return 0;
}