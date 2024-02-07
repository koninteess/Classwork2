#include <iostream> // Include the input/output stream library for basic I/O operations
using namespace std;

// A linked list node
class Node {
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node in the list
};

// Given a node prev_node, insert a new
// node after the given prev_node
void insertAfter(Node* prev_node, int new_data) {
    // Check if the given prev_node is NULL
    if (prev_node == NULL) {
        cout << "The given previous node cannot be NULL" << endl; // Print error message
        return; // Exit the function
    }
    // Allocate memory for the new node
    Node* new_node = new Node();
    // Set the data of the new node
    new_node->data = new_data;
    // Make the next pointer of the new node point to the next node of the previous node
    new_node->next = prev_node->next;
    // Make the next pointer of the previous node point to the new node
    prev_node->next = new_node;
}

// Function to insert element in LL
void push(Node** head_ref, int new_data) {
    // Allocate memory for the new node
    Node* new_node = new Node();
    // Set the data of the new node
    new_node->data = new_data;
    // Make the next pointer of the new node point to the current head of the list
    new_node->next = (*head_ref);
    // Move the head pointer to point to the new node
    (*head_ref) = new_node;
}

// This function prints contents of
// linked list starting from head
void printList(Node* node) {
    // Traverse the linked list and print the data of each node
    while (node != NULL) {
        cout << " " << node->data; // Print the data of the current node
        node = node->next; // Move to the next node
    }
    cout << endl; // Print a newline character after printing the list
}

int main() {
    // Start with the empty list
    Node* head = NULL;

    // Insert some elements at the beginning
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);

    // Print the initial linked list
    cout << "Created Linked list is:";
    printList(head);

    // Insert 1 after 2
    insertAfter(head->next, 1);

    // Print the updated linked list
    cout << "After inserting 1 after 2:";
    printList(head);

    return 0;
}
