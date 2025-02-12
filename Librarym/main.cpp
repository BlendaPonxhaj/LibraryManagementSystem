#include <iostream>
#include "FileHandler.h"

using namespace std;

int main() {
    int size;
    cout << "Sa libra do te ruani? ";
    cin >> size;

    cin.ignore(); // Clear any leftover newline character

    string* books = new string[size]; 

    cout << "Shkruani titujt e librave:\n";
    for (int i = 0; i < size; i++) {
        cout << "Libri " << i + 1 << ": ";
        cin >> books[i]; 
    }

    FileHandler handler;
    handler.RuajLibrat(books, size);

    cout << "Librat jane ruajtur!\n";

    delete[] books; 

    return 0;
}
