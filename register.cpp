#include <iostream>
#include <fstream>
#include <string>
#include<cstring>
using namespace std;
/*
   Changes I have Made
   Saving In dat File
*/
struct User{
   char userName[50];
   char userPass[50];
};
bool usernameExists(const string &username) {
    ifstream fin("users.dat", ios::binary);
    User tempUser;
    while (fin.read((char*)&tempUser, sizeof(tempUser))) {
        // Compare input with the data read from file
        if (username == tempUser.userName ) {
            fin.close();
            return true;
        }
    }
    return false;
}

void registerUser() {
    User newUser;
    string username, password;

    cout << "\n--- Register ---\n";
    cout << "Enter a username: ";
    cin >> username;

    if (usernameExists(username)) {
        cout << " Username already exists! Try a different one.\n";
        return;
    }

    cout << "Enter a password: ";
    //Passwords Can Include Space,Using Cin Normally Skips This
    cin.ignore();
    getline(cin,password);
    cin.clear(); //Clears Buffer
     strcpy(newUser.userName,username.c_str());
     strcpy(newUser.userPass,password.c_str());
    ofstream fout("users.dat", ios::binary | ios::app);
    fout.write((char*)&newUser, sizeof(newUser));
    fout.close();

    cout << " Registration successful!\n";
}

void loginUser() {
    User tempUser;
    string username, password;
    bool found = false;

    cout << "\n--- Login ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin.ignore();
    getline(cin,password);
    cin.clear();
    ifstream fin("users.dat", ios::binary);

    while (fin.read((char*)&tempUser, sizeof(tempUser))) {
        // Compare input with the data read from file
        if (username == tempUser.userName && password == tempUser.userPass) {
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
    ifstream fin("users.dat" , ios::binary);
    User tempUser;

    cout << "\n--- Registered Users ---\n";

    bool empty = true;
      while (fin.read((char*)&tempUser, sizeof(tempUser))) {
        cout << "- " << tempUser.userName << "\n";
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
