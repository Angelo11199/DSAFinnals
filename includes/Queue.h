#ifndef QUEUE_H
#define QUEUE_H
template <typename T>
class Queue {
   private:
    struct Node {
        T data;
        Node* next;
    };
    Node* head;
    Node* tail;
    int size;

   public:
    Queue() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    ~Queue() {
        Node* current = head;
        Node* next;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
    }
    void enqueue(T dataStruct) {
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
    void dequeue() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
    void print() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    int getSize() {
        return size;
    }
    bool isEmpty() {
        return size == 0;
    }
    T front() {
        if (head == nullptr) {
            return -1;
        }
        return head->data;
    }
    T back() {
        if (tail == nullptr) {
            return -1;
        }
        return tail->data;
    }
};
#endif