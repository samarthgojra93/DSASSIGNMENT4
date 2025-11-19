#include <iostream>
#include <queue>
using namespace std;

class StackOneQueue {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        int size = q.size();
        while (size > 1) {
            q.push(q.front());
            q.pop();
            size--;
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack Empty\n"; return;
        }
        cout << "Popped: " << q.front() << endl;
        q.pop();
    }

    void top() {
        if (q.empty()) cout << "Empty\n";
        else cout << "Top: " << q.front() << endl;
    }
};
