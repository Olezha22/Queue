#pragma once
#include <iostream>

using namespace std;

template<typename T>
class Queue {
private:
    struct QueueNode {
        T data;
        QueueNode* next;

        QueueNode(const T& d) : data(d), next(nullptr) {}
    };

    QueueNode* first;
    QueueNode* last;

public:
    Queue() : first(nullptr), last(nullptr) {}

    void push(const T& data) {
        QueueNode* newNode = new QueueNode(data);
        if (isEmpty()) {
            first = last = newNode;
        }
        else {
            last->next = newNode;
            last = newNode;
        }
    }

    T pop() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        }
        T data = first->data;
        QueueNode* temp = first;
        first = first->next;
        delete temp;
        if (first == nullptr) {
            last = nullptr;
        }
        return data;
    }

    bool isEmpty() const {
        return first == nullptr;
    }

    int calculateSize() const {
        int count = 0;
        QueueNode* temp = first;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};


template<typename T>
class PriorityQueue {
private:
    struct PriorityNode {
        T data;
        int priority;
        PriorityNode* next;

        PriorityNode(const T& d, int p) : data(d), priority(p), next(nullptr) {}
    };

    PriorityNode* first;
    PriorityNode* last;

public:
    PriorityQueue() : first(nullptr), last(nullptr) {}

    void push(const T& data, int priority) {
        PriorityNode* newNode = new PriorityNode(data, priority);
        if (isEmpty() || priority > first->priority) {
            newNode->next = first;
            first = newNode;
        }
        else {
            PriorityNode* temp = first;
            while (temp->next != nullptr && temp->next->priority >= priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        if (last == nullptr) {
            last = newNode;
        }
    }

    T pop() {
        if (isEmpty()) {
            cout << "Priority Queue is empty" << endl;
        }
        T data = first->data;
        PriorityNode* temp = first;
        first = first->next;
        delete temp;
        if (first == nullptr) {
            last = nullptr;
        }
        return data;
    }

    bool isEmpty() const {
        return first == nullptr;
    }

    int calculateSize() const {
        int count = 0;
        PriorityNode* temp = first;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};