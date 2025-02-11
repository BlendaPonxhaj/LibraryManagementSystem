#include <iostream>
#include "FileHandler.h"

using namespace std;

int main() {
	string books[] = { "Book 1","Book 2","Book 3" };
	int size = 3;

	FileHandler handler;
	handler.RuajLibrat(books, size);

	cout << "Librat jane ruajtur!\n";

	return 0;
}