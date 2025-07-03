#include "Header.h"
//used chatgpt to help with creation of this single linked list class
template <typename Item_Type>
class Single_Linked_List {
private:
    struct Node {
        Item_Type data;
        Node* next;

        Node(const Item_Type& data) : data(data), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t num_items;

public:
    // Constructor
    Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

    // Destructor
    ~Single_Linked_List() {
        while (!empty()) {
            pop_front();
        }
    }

    // Push item to the front
    void push_front(const Item_Type& item) {
        Node* new_node = new Node(item);
        new_node->next = head;
        head = new_node;
        if (num_items == 0)
            tail = new_node;
        ++num_items;
    }

    // Push item to the back
    void push_back(const Item_Type& item) {
        Node* new_node = new Node(item);
        if (empty()) {
            head = tail = new_node;
        }
        else {
            tail->next = new_node;
            tail = new_node;
        }
        ++num_items;
    }

    // Pop from front
    void pop_front() {
        if (empty()) return;
        Node* old_head = head;
        head = head->next;
        delete old_head;
        --num_items;
        if (num_items == 0)
            tail = nullptr;
    }

    // Pop from back
    void pop_back() {
        if (empty()) return;
        if (num_items == 1) {
            delete head;
            head = tail = nullptr;
        }
        else {
            Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
        --num_items;
    }

    // Get front item
    Item_Type front() const {
        if (empty()) throw std::runtime_error("List is empty");
        return head->data;
    }

    // Get back item
    Item_Type back() const {
        if (empty()) throw std::runtime_error("List is empty");
        return tail->data;
    }

    // Check if empty
    bool empty() const {
        return num_items == 0;
    }

    // Insert at index
    void insert(size_t index, const Item_Type& item) {
        if (index == 0) {
            push_front(item);
        }
        else if (index >= num_items) {
            push_back(item);
        }
        else {
            Node* current = head;
            for (size_t i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            Node* new_node = new Node(item);
            new_node->next = current->next;
            current->next = new_node;
            ++num_items;
        }
    }

    // Remove at index
    bool remove(size_t index) {
        if (index >= num_items) return false;
        if (index == 0) {
            pop_front();
            return true;
        }
        Node* current = head;
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = temp->next;
        if (temp == tail)
            tail = current;
        delete temp;
        --num_items;
        return true;
    }

    // Find item
    size_t find(const Item_Type& item) {
        Node* current = head;
        size_t index = 0;
        while (current != nullptr) {
            if (current->data == item) {
                return index;
            }
            current = current->next;
            ++index;
        }
        return num_items; // Not found
    }

    // Get size
    size_t size() const {
        return num_items;
    }
    void print() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

