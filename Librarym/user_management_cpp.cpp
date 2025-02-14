#include <iostream>
#include <string>
using namespace std;

struct User {
    string name;
    string pass;
    string role; 
};

void showMenu(string title, string options[], int count) {
    cout << "\n=== " << title << " ===" << endl;
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << options[i] << endl;
    }
    cout << "=====================" << endl;
}


void signUp(User list[], int& count) {
    string name, pass, role;

    cout << "\nEnter a username: ";
    cin >> name;

    for (int i = 0; i < count; i++) {
        if (list[i].name == name) {
            cout << "Username taken! Try another one." << endl;
            return;
        }
    }

    cout << "Enter a password: ";
    cin >> pass;

    cout << "Enter role (Admin/Member): ";
    cin >> role;

    if (role != "Admin" && role != "Member") {
        cout << "Invalid role! Must be 'Admin' or 'Member'." << endl;
        return;
    }

    list[count].name = name;
    list[count].pass = pass;
    list[count].role = role;
    count++;

    cout << "Account created! Welcome, " << name << "!" << endl;
}


int logIn(User list[], int count) {
    string name, pass;

    cout << "\nEnter username: ";
    cin >> name;

    cout << "Enter password: ";
    cin >> pass;

    for (int i = 0; i < count; i++) {
        if (list[i].name == name && list[i].pass == pass) {
            cout << "Login successful! Hi, " << list[i].name << " (" << list[i].role << ")." << endl;
            return i; 
        }
    }

    cout << "Oops! Wrong username or password." << endl;
    return -1; 
}

int main() {
    User users[100]; 
    int userCount = 0; 
    int loggedInUser = -1; 

    string mainMenu[] = { "Login", "Sign Up", "Exit" };
    string adminMenu[] = { "View Users", "Add User", "Logout" };
    string memberMenu[] = { "View Profile", "Logout" };

    cout << "🌟 Welcome to the User Management System! 🌟" << endl;

    while (true) {
        if (loggedInUser == -1) {
            
            showMenu("Main Menu", mainMenu, 3);

            int choice;
            cout << "Choose an option: ";
            cin >> choice;

            if (choice == 1) {
                loggedInUser = logIn(users, userCount);
            }
            else if (choice == 2) {
                signUp(users, userCount);
            }
            else if (choice == 3) {
                cout << "Goodbye! 👋" << endl;
                break;
            }
            else {
                cout << "Invalid choice! Try again." << endl;
            }
        }
        else {
            
            if (users[loggedInUser].role == "Admin") {
                showMenu("Admin Menu", adminMenu, 3);

                int choice;
                cout << "Choose an option: ";
                cin >> choice;

                if (choice == 1) {
                    cout << "\n=== Users ===" << endl;
                    for (int i = 0; i < userCount; i++) {
                        cout << "Username: " << users[i].name << ", Role: " << users[i].role << endl;
                    }
                }
                else if (choice == 2) {
                    signUp(users, userCount);
                }
                else if (choice == 3) {
                    loggedInUser = -1;
                    cout << "Logged out successfully!" << endl;
                }
                else {
                    cout << "Invalid choice! Try again." << endl;
                }
            }
            else if (users[loggedInUser].role == "Member") {
                showMenu("Member Menu", memberMenu, 2);

                int choice;
                cout << "Choose an option: ";
                cin >> choice;

                if (choice == 1) {
                    cout << "\n=== Profile ===" << endl;
                    cout << "Username: " << users[loggedInUser].name << endl;
                    cout << "Role: " << users[loggedInUser].role << endl;
                }
                else if (choice == 2) {
                    loggedInUser = -1;
                    cout << "Logged out successfully!" << endl;
                }
                else {
                    cout << "Invalid choice! Try again." << endl;
                }
            }
        }
    }

    return 0;
}