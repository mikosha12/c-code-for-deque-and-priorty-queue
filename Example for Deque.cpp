/**
 * C++ example to demonstrate Deque implementation using Doubly Linked List
 */
#include <iostream>
using namespace std;

// Doubly list node representation
struct Node
{
    int element;
    Node* prev;
    Node* next;
};

/**
 * Deque implementation using Doubly Linked List
 */
class Deque
{
private:
    // Front ptr
    Node* front;

    // Rear ptr
    Node* rear;

public:
    // Constructor
    Deque() : front(NULL), rear(NULL) {
    }

    // Insert the new element at Front side
    void insertFront(int element) {
        // Step 1. Create the new node
        Node* new_node = new Node();
        if (new_node == NULL) {
            cout << "Memory overflow" << endl;
            return;
        }
        new_node->element = element;

        // Step 2. Check if the list is empty
        if (front == NULL) {
            // Step 3. If true, set Front and Rear to point the new node and return
            new_node->prev = NULL;
            new_node->next = NULL;
            front = new_node;
            rear = new_node;
            return;
        }

        // Step 4. If false, link the new node at Front side
        new_node->prev = NULL;
        new_node->next = front;
        front->prev = new_node;

        // Step 5. Change the Front ptr to point the new node
        front = new_node;
    }

    // Insert the new element at Rear side
    void insertRear(int element) {
        // Step 1. Create the new node
        Node* new_node = new Node();
        if (new_node == NULL) {
            cout << "Memory overflow" << endl;
            return;
        }
        new_node->element = element;

        // Step 2. Check if the list is empty
        if (front == NULL) {
            // Step 3. If true, set Front and Rear to point the new node and return
            new_node->prev = NULL;
            new_node->next = NULL;
            front = new_node;
            rear = new_node;
            return;
        }

        // Step 4. If false, link the new node at Rear side
        new_node->prev = rear;
        new_node->next = NULL;
        rear->next = new_node;

        // Step 5. Change the Rear ptr to point the new node
        rear = new_node;
    }

    // Delete the element from Front side
    void deleteFront() {
        // Step 1. Check if the Deque is empty, and return if true.
        if (front == NULL) {
            cout << "Deque is empty" << endl;
            return;
        }

        // Step 2. Remember the front node in a temporary pointer
        Node* tmp = front;

        // Step 3. Check if the Front and Rear are in the same position
        // This occurs when deleting the last element
        if (front == rear) {
            // Step 4. If true, reset the Front and Rear pointers to NULL
            front = NULL;
            rear = NULL;

        } else {
            // Step 5. If false, move the Front to point the next node
            front = front->next;
            front->prev = NULL;
        }

        // Step 6. Delete the first node referenced by the temporary pointer
        delete tmp;
    }

    // Delete the element from Rear side
    void deleteRear() {
        // Step 1. Check if the Deque is empty, and return if true.
        if (front == NULL) {
            cout << "Deque is empty" << endl;
            return;
        }

        // Step 2. Remember the rear node in a temporary pointer
        Node* tmp = rear;

        // Step 3. Check if the Front and Rear are in the same position
        // This occurs when deleting the last element
        if (front == rear) {
            // Step 4. If true, reset the Front and Rear pointers to NULL
            front = NULL;
            rear = NULL;

        } else {
            // Step 5. If false, move the Rear to point the previous node
            rear = rear->prev;
            rear->next = NULL;
        }

        // Step 6. Delete the last node referenced by the temporary pointer
        delete tmp;
    }

    // Get the Front element
    int getFront() {
        if (front == NULL) {
            cout << "Deque is empty" << endl;
            return -1;
        }
        return front->element;
    }

    // Get the Rear element
    int getRear() {
        if (rear == NULL) {
            cout << "Deque is empty" << endl;
            return -1;
        }
        return rear->element;
    }

    // Print the Queue
    void print(string msg) {
        cout << msg << endl;
        if (front == NULL) {
            cout << "Deque is empty" << endl;
            return;
        }

        cout << "FRONT -->  ";
        for (Node* p = front ; p != NULL ; p = p->next) {
            cout << "[" << p->element << "]" << ((p != rear)? "--" : "");
        }
        cout << "  <-- REAR" << endl << endl;
    }
};

// The main function to begin the execution
int main()
{
    // Create a Deque
    Deque queue;

    // Insert Front
    queue.insertFront(5);
    queue.print("Queue after insertFront(5)");
    queue.insertFront(3);
    queue.print("Queue after insertFront(3)");
    queue.insertFront(1);
    queue.print("Queue after insertFront(1)");

    // Insert Rear
    queue.insertRear(10);
    queue.print("Queue after insertRear(10)");
    queue.insertRear(20);
    queue.print("Queue after insertRear(20)");
    queue.insertRear(30);
    queue.print("Queue after insertRear(30)");

    // Delete Front
    queue.deleteFront();
    queue.print("Queue after deleteFront()");
    queue.deleteFront();
    queue.print("Queue after deleteFront()");
    queue.deleteFront();
    queue.print("Queue after deleteFront()");

    // Delete Rear
    queue.deleteRear();
    queue.print("Queue after deleteRear()");
    queue.deleteRear();
    queue.print("Queue after deleteRear()");
    queue.deleteRear();
    queue.print("Queue after deleteRear()");
}
