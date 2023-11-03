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
