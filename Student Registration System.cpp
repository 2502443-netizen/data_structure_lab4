#include <iostream>
using namespace std;

struct Node {
    int rollNumber;
    Node* next;
};

void addStudent(Node*& head, int rollNumber) {
    Node* newNode = new Node;
    newNode->rollNumber = rollNumber;
    newNode->next =nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayStudents(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->rollNumber;
        if (temp->next != nullptr)
            cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

void searchStudent(Node* head, int rollNumber) {
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->rollNumber == rollNumber) {
            cout << "Student Found" << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Student Not Found" << endl;
}

int main() {
    Node* head = nullptr;

    addStudent(head, 101);
    addStudent(head, 105);
    addStudent(head, 108);
    addStudent(head, 112);

    cout << "Registered Students:" << endl;
    displayStudents(head);

    int rollNumber;
    cout << "Enter Roll Number to Search: ";
    cin >> rollNumber;

    searchStudent(head, rollNumber);

    return 0;
}
