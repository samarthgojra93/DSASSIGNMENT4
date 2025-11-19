#include <iostream>
using namespace std;

class Queue {
    int front, rear, size;
    int *arr;
public:
    Queue(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    bool isFull() {
        return rear == size - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is FULL\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = x;
        cout << "Inserted: " << x << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY\n";
            return;
        }
        cout << "Deleted: " << arr[front++] << endl;
    }

    void peek() {
        if (isEmpty()) cout << "Queue Empty\n";
        else cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue Empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q(10);
    int ch, val;

    while (true) {
        cout << "\n1.Enqueue  2.Dequeue  3.isEmpty  4.isFull  5.Display  6.Peek  7.Exit\n";
        cin >> ch;

        switch (ch) {
            case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: cout << (q.isEmpty() ? "Empty\n" : "Not Empty\n"); break;
            case 4: cout << (q.isFull() ? "Full\n" : "Not Full\n"); break;
            case 5: q.display(); break;
            case 6: q.peek(); break;
            case 7: return 0;
        }
    }
}
