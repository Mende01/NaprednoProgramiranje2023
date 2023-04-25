#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() 
{
    string filename;
    cout << "Vnesi go imeto na fajlot: ";
    cin >> filename;
    cin.ignore(); 
    ofstream outFile(filename, ios::app);
    if (!outFile) 
    {
        cerr << "Greska: Ne moze da se otvori dadotekata za pisuvanje." << endl;
        return 1;
    }
    string textToAdd;
    cout << "Vnesi tekst za da dodades nekoj fajl: ";
    getline(cin, textToAdd);
    outFile << textToAdd << endl;
    outFile.close();

    return 0;
}