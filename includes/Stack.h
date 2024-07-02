#ifndef STACK_H
#define STACK_H
template <typename T>
class Stack {
   private:
    struct Node {
        T data;
        Node* next;
    };
    Node* head;
    int size;

   public:
    Stack() {
        head = nullptr;
        size = 0;
    }
    ~Stack() {
        Node* current = head;
        Node* next;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
    }
    void push(T dataStruct) {
        Node* newNode = new Node;
        newNode->data = dataStruct;
        newNode->next = head;
        head = newNode;
        size++;
    }
    void pop() {
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
};
#endif