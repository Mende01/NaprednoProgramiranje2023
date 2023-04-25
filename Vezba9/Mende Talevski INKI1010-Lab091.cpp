#include <iostream>
#include <cctype>
using namespace std;
int main() 
{
    string recenica;
    cout << " ";
    getline(cin, recenica);

    int num_chars = recenica.length();
    bool has_lowercase = false;
    bool has_uppercase = false;
    bool has_digit = false;
    bool has_special =false;

    for (char c : recenica) {
        if (islower(c)) {
            has_lowercase = true;
        } else if (isupper(c)) {
            has_uppercase = true;
        } else if (isdigit(c)) {
            has_digit = true;
        } else if (!isalnum(c)) {
            has_special = true;
        }
    }

    cout << "\n";
    cout << "- " << num_chars << " characters\n";
    cout << "- " << (has_lowercase ? "lowercase bukvi\n" : "nema lowercase bukvi\n");
    cout << "- " << (has_uppercase ? "uppercase bukvi\n" : "nema uppercase bukvi\n");
    cout << "- " << (has_digit ? "brojki\n" : "nema brojki\n");
    cout << "- " << (has_special ? "specijalni karakteri\n" : "nema specijalni karakteri\n");

    return 0;
}