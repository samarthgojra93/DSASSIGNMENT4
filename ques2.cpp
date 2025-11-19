#include <iostream>
using namespace std;

class CircularQueue {
    int front, rear, size;
    int *arr;
public:
    CircularQueue(int n) {
        size = n;
        arr = new int[n];
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue FULL\n";
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % size;
        arr[rear] = x;
        cout << "Inserted " << x << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue EMPTY\n";
            return;
        }
        cout << "Deleted " << arr[front] << endl;

        if (front == rear) front = rear = -1;
        else front = (front + 1) % size;
    }

    void peek() {
        if (isEmpty()) cout << "Empty\n";
        else cout << "Front: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Empty\n"; return;
        }
        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq(10);
    int ch, val;

    while (true) {
        cout << "\n1.Enqueue  2.Dequeue  3.isEmpty  4.isFull  5.Display  6.Peek  7.Exit\n";
        cin >> ch;

        switch(ch) {
            case 1: cout << "Enter value: "; cin >> val; cq.enqueue(val); break;
            case 2: cq.dequeue(); break;
            case 3: cout << (cq.isEmpty() ? "Empty\n" : "Not Empty\n"); break;
            case 4: cout << (cq.isFull() ? "Full\n" : "Not Full\n"); break;
            case 5: cq.display(); break;
            case 6: cq.peek(); break;
            case 7: return 0;
        }
    }
}
