#include "FileHandler.h"
#include <fstream>
#include <iostream>

using namespace std;
void FileHandler::RuajLibrat(string books[], int size) {
	ofstream file("books.txt");
	if (file) {
		for (int i = 0; i < size; i++) {
			file << books[i] << endl;
		}
	}
	file.close();
}

