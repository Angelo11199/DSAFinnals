#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
template <typename T>
class LinkedList {
   protected:
    struct Node {
        T data;
        Node* next;
    };
    Node* head;
    Node* tail;
    int size;

   public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    ~LinkedList() {
        Node* current = head;
        Node* next;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
    }
    void add(T dataStruct) {
        Node* newNode = new Node;
        newNode->data = dataStruct;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    void remove(T data) {
        Node* current = head;
        Node* previous = nullptr;
        while (current != nullptr) {
            if (current->data.id == data.id) {
                if (previous == nullptr) {
                    head = current->next;
                } else {
                    previous->next = current->next;
                }
                delete current;
                size--;
                return;
            }
            previous = current;
            current = current->next;
        }
    }
    void print() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << std::endl;
            current = current->next;
        }
    }
    int getSize() {
        return size;
    }
};

#endif