#include <iostream>
#include "queue.h"

int main() {

    PriorityQueue<int> pq;
    pq.push(5, 2);
    pq.push(10, 1);
    pq.push(34, 3);

    cout << "Priority Queue size: " << pq.calculateSize() << endl;

    cout << "Priority Queue: ";
    while (!pq.isEmpty()) {
        cout << pq.pop() << " ";
    }
    cout << endl;

    Queue<string> q;
    q.push("one");
    q.push("two");
    q.push("three");
    q.push("four");

    cout << "Queue size: " << q.calculateSize() << endl;

    cout << "Queue: ";
    while (!q.isEmpty()) {
        cout << q.pop() << " ";
    }
    cout << endl;

    return 0;
}
