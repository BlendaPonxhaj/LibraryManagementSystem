#include "FileHandler.h" // Include the FileHandler header file (contains struct and function declarations)
#include <iostream> // Used for input/output operations
#include <fstream> // Used for file handling operations (ifstream, ofstream)

using namespace std; // Allows using standard library names without std:: prefix



void FileHandler::saveToFile(const string& filename, const string data[], int size) { 
	ofstream file(filename); // Open the file in write mode (overwrites existing content)
	if (!file) { // Check if the file opened successfully
		cout << "Error opening file: " << filename << endl;
		return; // Exit function if the file couldn't be opened
	}
	for (int i = 0; i < size; i++) {
		file << data[i] << endl; // Write each string from the array to the file (new line for each entry)
	}
	file.close(); // Close the file after writing
}


int FileHandler::loadFromFile(const string& filename, string data[], int maxSize) {
	ifstream file(filename); // Open the file for reading
	if (!file) { // If the file doesn't open, print error and exit the function
		cout << "Error opening file: " << filename << endl;
		return 0; // Return 0 since no data could be read
	}
	int count = 0; // Keeps track of the number of lines read
	while (count < maxSize && getline(file, data[count])) { // Read the file line by line into the array
		count++; // Increase count for each line read
	}
	file.close(); // Close the file after reading
	return count; // Return the total number of lines that were read 
}


void FileHandler::appendToFile(const string& filename, const string& newData) {
	ofstream file(filename, ios::app); // Open file in append mode (doesn't overwrite)
	if (!file) { // Check if file opening failed
		cout << "Error opening file: " << filename << endl;
		return; // Exit the function immediately
	}
	file << newData << '\n'; // Write new data to the file
	file.close(); // Close the file only if it was successfully opened
}

bool FileHandler::fileExists(const string& filename) {
	ifstream file(filename); // Try to open the file in read mode
	return file.good(); // Returns true if the file exists, false otherwise
}
