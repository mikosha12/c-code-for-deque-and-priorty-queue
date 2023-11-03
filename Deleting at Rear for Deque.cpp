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
