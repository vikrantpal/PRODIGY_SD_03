#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Contact {
    string name;
    string phoneNumber;
    string email;
};

void addContact(vector<Contact> &contacts) {
    Contact newContact;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, newContact.name);
    cout << "Enter phone number: ";
    getline(cin, newContact.phoneNumber);
    cout << "Enter email address: ";
    getline(cin, newContact.email);
    contacts.push_back(newContact);
    cout << "Contact added successfully!" << endl;
}

void viewContacts(const vector<Contact> &contacts) {
    if (contacts.empty()) {
        cout << "No contacts available." << endl;
        return;
    }
    for (size_t i = 0; i < contacts.size(); ++i) {
        cout << i + 1 << ". Name: " << contacts[i].name
             << ", Phone: " << contacts[i].phoneNumber
             << ", Email: " << contacts[i].email << endl;
    }
}

void editContact(vector<Contact> &contacts) {
    if (contacts.empty()) {
        cout << "No contacts available to edit." << endl;
        return;
    }
    int index;
    cout << "Enter the contact number to edit: ";
    cin >> index;
    if (index < 1 || index > contacts.size()) {
        cout << "Invalid contact number." << endl;
        return;
    }
    Contact &contact = contacts[index - 1];
    cout << "Editing contact: " << contact.name << endl;
    cout << "Enter new name (leave blank to keep current): ";
    cin.ignore();
    string name;
    getline(cin, name);
    if (!name.empty()) {
        contact.name = name;
    }
    cout << "Enter new phone number (leave blank to keep current): ";
    string phoneNumber;
    getline(cin, phoneNumber);
    if (!phoneNumber.empty()) {
        contact.phoneNumber = phoneNumber;
    }
    cout << "Enter new email address (leave blank to keep current): ";
    string email;
    getline(cin, email);
    if (!email.empty()) {
        contact.email = email;
    }
    cout << "Contact updated successfully!" << endl;
}

void deleteContact(vector<Contact> &contacts) {
    if (contacts.empty()) {
        cout << "No contacts available to delete." << endl;
        return;
    }
    int index;
    cout << "Enter the contact number to delete: ";
    cin >> index;
    if (index < 1 || index > contacts.size()) {
        cout << "Invalid contact number." << endl;
        return;
    }
    contacts.erase(contacts.begin() + index - 1);
    cout << "Contact deleted successfully!" << endl;
}

void displayMenu() {
    cout << "\nContact Manager" << endl;
    cout << "1. Add new contact" << endl;
    cout << "2. View contacts" << endl;
    cout << "3. Edit contact" << endl;
    cout << "4. Delete contact" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option: ";
}

int main() {
    vector<Contact> contacts;
    int choice;

    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                addContact(contacts);
                break;
            case 2:
                viewContacts(contacts);
                break;
            case 3:
                editContact(contacts);
                break;
            case 4:
                deleteContact(contacts);
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
