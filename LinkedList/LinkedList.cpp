#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
private:
    Node* head;
    Node* tail;

public:
    List() {
        head = tail = NULL;
    }

    void ayush_update(int id, string newName);
    void ayush_sort();
    void ayush_swap(int id1, int id2);

    void push_front(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
            return;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void insert(int val, int pos) {
        if(pos < 0) {
            cout << "Invalid position\n";
            return;
        }

        if(pos == 0) {
            push_front(val);
            return;
        }

        Node* temp = head;
        for(int i=0; i<pos-1; i++) {
            if(temp == NULL) {
                cout << "Invalid postion\n";
                return;
            }
            temp = temp->next;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void push_back(int val) {
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {
        if(head == NULL) {
            cout << "LL is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        temp->next = NULL;

        delete temp;
    }

    void pop_back() {
        if(head == NULL) {
            cout << "LL is empty" << endl;
            return;
        }

        Node *temp = head;
        while(temp->next != tail) {
            temp = temp->next;
        }

        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    int search(int val) {
        Node* temp = head;
        int idx = 0;

        while(temp != NULL) {
            if(temp->data == val) {
                return idx;
            }

            temp = temp->next;
            idx++;
        }

        return -1;
    }

    void printLL() {
        Node* temp = head;

        while(temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    List l1;

    l1.push_front(4);
    l1.push_front(3);
    l1.push_front(1);

    l1.insert(2, 1);

    l1.printLL();

    return 0;
}