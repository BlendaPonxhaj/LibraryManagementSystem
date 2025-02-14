#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Book {
    int id;
    string title;
    bool isBorrowed;

    Book(int _id, string _title) : id(_id), title(_title), isBorrowed(false) {}
};

class Library {
private:
    vector<Book> books;
public:
    void addBook(int id, string title) {
        books.push_back(Book(id, title));
    }

    void displayBooks() {
        cout << "\nAvailable Books:" << endl;
        for (const auto& book : books) {
            cout << "ID: " << book.id << " | Title: " << book.title;
            if (book.isBorrowed) {
                cout << " (Borrowed)";
            }
            cout << endl;
        }
    }

    void borrowBook(int id) {
        for (auto& book : books) {
            if (book.id == id) {
                if (!book.isBorrowed) {
                    book.isBorrowed = true;
                    cout << "You have successfully borrowed: " << book.title << endl;
                }
                else {
                    cout << "Sorry, this book is already borrowed." << endl;
                }
                return;
            }
        }
        cout << "Book with ID " << id << " not found." << endl;
    }

    void returnBook(int id) {
        for (auto& book : books) {
            if (book.id == id) {
                if (book.isBorrowed) {
                    book.isBorrowed = false;
                    cout << "You have successfully returned: " << book.title << endl;
                }
                else {
                    cout << "This book was not borrowed." << endl;
                }
                return;
            }
        }
        cout << "Book with ID " << id << " not found." << endl;
    }
};

int main() {
    Library library;
    library.addBook(1, "The Catcher in the Rye");
    library.addBook(2, "1984");
    library.addBook(3, "To Kill a Mockingbird");

    int choice, bookId;
    do {
        cout << "\nLibrary Management System" << endl;
        cout << "1. Display Books" << endl;
        cout << "2. Borrow Book" << endl;
        cout << "3. Return Book" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            library.displayBooks();
            break;
        case 2:
            cout << "Enter book ID to borrow: ";
            cin >> bookId;
            library.borrowBook(bookId);
            break;
        case 3:
            cout << "Enter book ID to return: ";
            cin >> bookId;
            library.returnBook(bookId);
            break;
        case 4:
            cout << "Exiting the system. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
