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
    /**
     * @brief Constructor to initialize the linked list
     *
     */
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    Node* getHead() {
        return head;
    }

    /**
     * @brief Destructor to clean up memory allocated for the linked list
     *
     */
    ~LinkedList() {
        std::cout << "Linked list Deleted" << std::endl;
        // Node* current = head;
        // while (current != nullptr) {
        //     Node* next = current->next;  // Save next node
        //     delete current;              // Delete the current node
        //     current = next;              // Move to the next node
        // }
        // head = nullptr;
    }

    /**
     * @brief Adds a new node with given data to the end of the linked list
     *
     * @param dataStruct Data to be stored in the new node
     */
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

    /**
     * @brief Removes the node with given data from the linked list
     *
     * @param data Data of the node to be removed
     */
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

    /**
     * @brief Prints all elements in the linked list
     *
     */
    void print() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << std::endl;
            current = current->next;
        }
    }

    /**
     * @brief Returns the current size of the linked list
     *
     * @return int Size of the linked list
     */
    int getSize() {
        return size;
    }
};

#endif