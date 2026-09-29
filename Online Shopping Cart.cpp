#include <iostream>
using namespace std;

struct Node {
    string productID;
    Node* next;
};

void addProduct(Node*& head, string productID) {
    Node* newNode = new Node;
    newNode->productID = productID;
    newNode->next = nullptr;

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

void displayCart(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->productID;
        if (temp->next != nullptr)
            cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

void removeProduct(Node*& head, string productID) {
    if (head == nullptr) {
        cout << "Product not found." << endl;
        return;
    }

    if (head->productID == productID) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr) {
        if (temp->next->productID == productID) {
            Node* deleteNode = temp->next;
            temp->next = temp->next->next;
            delete deleteNode;
            return;
        }
        temp = temp->next;
    }

    cout << "Product not found." << endl;
}

int main() {
    Node* head = nullptr;

    addProduct(head, "P101");
    addProduct(head, "P205");
    addProduct(head, "P310");
    addProduct(head, "P415");

    cout << "Shopping Cart:" << endl;
    displayCart(head);

    string productID;
    cout << "Remove Product: ";
    cin >> productID;

    removeProduct(head, productID);

    cout << "Updated Cart:" << endl;
    displayCart(head);

    return 0;
}
