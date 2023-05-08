#include <iostream>
#include <cstring>
using namespace std;
int main() {
    const char* str = "Miley Cyrus - Flowers ";
    const char* song = " Flowers ";
    const char* artist = "Miley Cyrus ";
    
    const char* ptr = str;
    
    cout << "Prv karakter: " << *ptr << std::endl;
    cout << "Addresa na prviot karakter: " << (void*)ptr << std::endl;
    cout << "Celosno ime: " << ptr << std::endl;
    
    int artist_len = strlen(artist);
    int offset = artist_len + 3;
    
    ptr += offset;
    
    cout << "Izveduvac: " << artist << std::endl;
    cout << "pomestuvanje: " << offset << std::endl;
    cout << "ime na pesna: " << ptr << std::endl;
    
    return 0;
}