//DeletionInLinkedList.cpp


#include <iostream>

using namespace std;

class Node {
public:
    int data;           // Data of the node
    Node* next;         // Pointer to the next node in the list

    // Constructor to initialize the node with data and nullptr as next pointer
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;         // Pointer to the first node in the list

public:
    // Constructor to initialize the linked list with nullptr as head pointer
    LinkedList() {
        head = nullptr;
    }

    // Function to insert a node at the end of the list
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);     // Create a new node with the given data
        if (head == nullptr) {              // If list is empty, make the new node the head
            head = newNode;
            return;
        }
        Node* temp = head;                  // Traverse the list to find the last node
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;               // Link the last node to the new node
    }

    // Function to delete the first node from the list
    void deleteAtBeginning() {
        if (head == nullptr) {              // If list is empty, print a message and return
            cout << "Linked list is empty. Nothing to delete." << endl;
            return;
        }
        Node* temp = head;                  // Store the head node in a temporary pointer
        head = head->next;                  // Move the head pointer to the next node
        delete temp;                        // Delete the old head node
    }

    // Function to delete the last node from the list
    void deleteAtEnd() {
        if (head == nullptr) {              // If list is empty, print a message and return
            cout << "Linked list is empty. Nothing to delete." << endl;
            return;
        }
        if (head->next == nullptr) {        // If list has only one node, delete it and update head
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;                  // Traverse the list to find the second last node
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;                  // Delete the last node
        temp->next = nullptr;               // Update the next pointer of the second last node
    }

    // Function to delete a node with a specific key from the list
    void deleteInMiddle(int key) {
        if (head == nullptr) {              // If list is empty, print a message and return
            cout << "Linked list is empty. Nothing to delete." << endl;
            return;
        }
        if (head->data == key) {            // If the key matches the data of the head node
            Node* temp = head;              // Store the head node in a temporary pointer
            head = head->next;              // Move the head pointer to the next node
            delete temp;                    // Delete the old head node
            return;
        }
        Node* temp = head;                  // Traverse the list to find the node with the key
        Node* prev = nullptr;               // Pointer to keep track of the previous node
        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {              // If key not found, print a message and return
            cout << "Key not found in the list." << endl;
            return;
        }
        prev->next = temp->next;            // Update the next pointer of the previous node
        delete temp;                        // Delete the node with the key
    }

    // Function to display the elements of the list
    void display() {
        Node* temp = head;                  // Start from the head node
        while (temp != nullptr) {           // Traverse the list until the end
            cout << temp->data << " ";      // Print the data of the current node
            temp = temp->next;              // Move to the next node
        }
        cout << endl;
    }

    // Destructor to deallocate memory used by the linked list
    ~LinkedList() {
        Node* temp = head;                  // Start from the head node
        while (temp != nullptr) {           // Traverse the list until the end
            Node* nextNode = temp->next;    // Store the next node in a temporary pointer
            delete temp;                    // Delete the current node
            temp = nextNode;                // Move to the next node
        }
        head = nullptr;                     // Set head to nullptr after all nodes are deleted
    }
};

// Main function to demonstrate the LinkedList class
int main() {
    LinkedList llist;

    // Insert elements
    llist.insertAtEnd(1);
    llist.insertAtEnd(2);
    llist.insertAtEnd(3);
    llist.insertAtEnd(4);
    llist.insertAtEnd(5);

    // Display the original list
    cout << "Original linked list:" << endl;
    llist.display();

    // Delete from beginning
    llist.deleteAtBeginning();
    cout << "After deleting from beginning:" << endl;
    llist.display();

    // Delete from end
    llist.deleteAtEnd();
    cout << "After deleting from end:" << endl;
    llist.display();

    // Delete from middle
    llist.deleteInMiddle(3);
    cout << "After deleting from middle:" << endl;
    llist.display();

    return 0;
}
