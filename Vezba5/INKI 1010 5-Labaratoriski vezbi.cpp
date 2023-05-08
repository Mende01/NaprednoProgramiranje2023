#include <iostream>
#include <string>

using namespace std;


void modifyName(string& firstName, string& lastName) {
    
    firstName.replace(0, 4, "@#$%");
    lastName.replace(0, 4, "@#$%");
}


void printName(string firstName, string lastName) {
    cout << "Orginalno ime: " << firstName << " " << lastName << endl;
    
    
    modifyName(firstName, lastName);
    
    cout << "Ime so znaci: " << firstName << " " << lastName << endl;
}

int main() {
    string firstName = "Ivana";
    string lastName = "Mitrevska";
    
    
    printName(firstName, lastName);
    
    return 0;
}