#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool usernameExists(const string &username) {
    ifstream fin("users.txt");
    string u, p;
    while (fin >> u >> p) {
        if (u == username)
            return true;
    }
    return false;
}

void registerUser() {
    string username, password;

    cout << "\n--- Register ---\n";
    cout << "Enter a username: ";
    cin >> username;

    if (usernameExists(username)) {
        cout << " Username already exists! Try a different one.\n";
        return;
    }

    cout << "Enter a password: ";
    cin >> password;

    ofstream fout("users.txt", ios::app);
    fout << username << " " << password << "\n";
    fout.close();

    cout << " Registration successful!\n";
}

void loginUser() {
    string username, password, u, p;
    bool found = false;

    cout << "\n--- Login ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream fin("users.txt");

    while (fin >> u >> p) {
        if (u == username && p == password) {
            found = true;
            break;
        }
    }
    fin.close();

    if (found)
        cout << " Login successful! Welcome " << username << "!\n";
    else
        cout << " Incorrect username or password.\n";
}

void showUsers() {
    ifstream fin("users.txt");
    string u, p;

    cout << "\n--- Registered Users ---\n";

    bool empty = true;
    while (fin >> u >> p) {
        cout << "- " << u << "\n";
        empty = false;
    }

    if (empty)
        cout << "(No users registered yet)\n";
}

int main() {
    int choice;

    while (true) {
        cout << "\n=== Simple Login & Registration System ===\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Show Registered Users\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1)
            registerUser();
        else if (choice == 2)
            loginUser();
        else if (choice == 3)
            showUsers();
        else if (choice == 4) {
            cout << "Exiting. Thank You!\n";
            break;
        }
        else
            cout << "Invalid option. Try again.\n";
    }

    return 0;
}
