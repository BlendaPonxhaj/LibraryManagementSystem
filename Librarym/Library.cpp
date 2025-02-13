#include "Library.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    string isbn;
};

void addBook(vector<Book>& books) {
    Book newBook;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, newBook.title);
    cout << "Enter author: ";
    getline(cin, newBook.author);
    cout << "Enter ISBN: ";
    getline(cin, newBook.isbn);

    books.push_back(newBook);
    cout << "Book added successfully!" << endl;
}

void displayBooks(const vector<Book>& books) {
    if (books.empty()) {
        cout << "No books available." << endl;
        return;
    }

    for (const auto& book : books) {
        cout << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.isbn << endl;
    }
}

void editBook(vector<Book>& books) {
    string isbn;
    cout << "Enter ISBN of the book to edit: ";
    cin.ignore();
    getline(cin, isbn);

    for (auto& book : books) {
        if (book.isbn == isbn) {
            cout << "Editing Book: " << book.title << endl;
            cout << "Enter new title: ";
            getline(cin, book.title);
            cout << "Enter new author: ";
            getline(cin, book.author);
            cout << "Enter new ISBN: ";
            getline(cin, book.isbn);
            cout << "Book updated successfully!" << endl;
            return;
        }
    }
    cout << "Book with ISBN " << isbn << " not found." << endl;
}

void deleteBook(vector<Book>& books) {
    string isbn;
    cout << "Enter ISBN of the book to delete: ";
    cin.ignore();
    getline(cin, isbn);

    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->isbn == isbn) {
            books.erase(it);
            cout << "Book deleted successfully!" << endl;
            return;
        }
    }
    cout << "Book with ISBN " << isbn << " not found." << endl;
}

void searchBook(const vector<Book>& books) {
    string searchTerm;
    cout << "Enter title or author or ISBN to search: ";
    cin.ignore();
    getline(cin, searchTerm);

    bool found = false;
    for (const auto& book : books) {
        if (book.title.find(searchTerm) != string::npos || book.author.find(searchTerm) != string::npos || book.isbn.find(searchTerm) != string::npos) {
            cout << "Found Book: Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.isbn << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No books found matching the search term." << endl;
    }
}

void saveToFile(const vector<Book>& books, const string& filename) {
    ofstream file(filename, ios::trunc);
    for (const auto& book : books) {
        file << book.title << "\n" << book.author << "\n" << book.isbn << "\n";
    }
}

void loadFromFile(vector<Book>& books, const string& filename) {
    ifstream file(filename);
    Book book;
    while (getline(file, book.title) && getline(file, book.author) && getline(file, book.isbn)) {
        books.push_back(book);
    }
}

int main() {
    vector<Book> books;
    string filename = "books.txt";
    loadFromFile(books, filename);

    int choice;
    do {
        cout << "\nBook Management System\n";
        cout << "1.	Add Book\n";
        cout << "2.	Edit Book\n";
        cout << "3.	Delete Book\n";
        cout << "4.	Search Book\n";
        cout << "5.	Display Books\n";
        cout << "6.	Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addBook(books);
            break;
        case 2:
            editBook(books);
            break;
        case 3:
            deleteBook(books);
            break;
        case 4:
            searchBook(books);
            break;
        case 5:
            displayBooks(books);
            break;
        case 6:
            saveToFile(books, filename);
            cout << "Exiting system... Changes saved!" << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}