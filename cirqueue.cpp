#include <iostream>
using namespace std;

class CircularQueue {
private:
    const int SIZE; 
    int *queue;     
    int front, rear;

public:
    CircularQueue(int size) : SIZE(size) {
        queue = new int[SIZE];
        front = rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is Full! Cannot insert " << value << endl;
            return;
        }
        if (isEmpty()) { 
            front = rear = 0;
        } else if (rear == SIZE - 1 && front != 0) { 
            rear = 0;
        } else {
            rear++;
        }
        queue[rear] = value;
        cout << value << " enqueued into the queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty! Nothing to dequeue.\n";
            return;
        }

        int deletedValue = queue[front];
        if (front == rear) { 
            front = rear = -1;
        } else if (front == SIZE - 1) { 
            front = 0;
        } else {
            front++;
        }
        cout << deletedValue << " dequeued from the queue.\n";
    }

    // Function to display the elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Circular Queue Elements: ";
        if (rear >= front) { 
            for (int i = front; i <= rear; i++)
                cout << queue[i] << " ";
        } else { 
            for (int i = front; i < SIZE; i++)
                cout << queue[i] << " ";
            for (int i = 0; i <= rear; i++)
                cout << queue[i] << " ";
        }
        cout << endl;
    }

    ~CircularQueue() {
        delete[] queue;
    }
};

int main() {
    int size, choice, value;

    // User-defined queue size
    cout << "Enter the size of the circular queue: ";
    cin >> size;

    CircularQueue cq(size);

    do {
        cout << "\nCircular Queue Operations:";
        cout << "\n1. Enqueue (Insertion)";
        cout << "\n2. Dequeue (Deletion)";
        cout << "\n3. Display Queue";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            cq.enqueue(value);
            break;

        case 2:
            cq.dequeue();
            break;

        case 3:
            cq.display();
            break;

        case 4:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
