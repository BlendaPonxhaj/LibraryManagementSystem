#include "FileHandler.h" // Include the FileHandler header file (contains struct and function declarations)
#include <iostream>		
#include <fstream>		 // Used for file handling operations (ifstream, ofstream)

using namespace std; 

void FileHandler::saveToFile(const string &filename, const string data[], int size)
{
	ofstream file(filename); // Open the file in write mode (overwrites existing content)
	if (!file)
	{ 
		cout << "Error opening file: " << filename << endl;
		return; // Exit function if the file couldn't be opened
	}
	for (int i = 0; i < size; i++)
	{
		file << data[i] << endl; // Write each string from the array to the file (new line for each entry)
	}
	file.close();
}

int FileHandler::loadFromFile(const string &filename, string data[], int maxSize)
{
	ifstream file(filename); // Open the file for reading
	if (!file)
	{ 
		cout << "Error opening file: " << filename << endl;
		return 0; // Return 0 since no data could be read
	}
	int count = 0; // Keeps track of the number of lines read
	while (count < maxSize && getline(file, data[count]))
	{			
		count++; // Increase count for each line read
	}
	file.close(); // Close the file after reading
	return count; // Return the total number of lines that were read
}
