#include <iostream>
using namespace std;
// Node class for the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};
// Function to display the linked list
void displayLinkedList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Creating an empty linked list
    Node* head = NULL;
    Node* tail = NULL;

    int numNodes;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    // Creating the linked list with user input values
    for (int i = 0; i < numNodes; i++) {
        int value;
        cout << "Enter the value for node " << i+1 << ": ";
        cin >> value;

        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Displaying the linked list
    displayLinkedList(head);

    // Clean up the memory
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
