#pragma once // Ensures that the header file is included only once in compilation

#include <string>  // For working with std::string
#include <fstream> // For file handling

using namespace std; // Allows using standard library names without std:: prefix

// Structure for handling file operations
struct FileHandler {
	void saveToFile(const string& filename, const string data[], int size); 
	//Overwrites a file with new data

	int loadFromFile(const string& filename, string data[], int maxSize); 
	//Reads data from a file into an array

};
