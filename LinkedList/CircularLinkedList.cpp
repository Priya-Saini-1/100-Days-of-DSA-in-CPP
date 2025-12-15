#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class CircularList {
    Node* head;
    Node* tail;

    public:
    CircularList(){
        head = tail = NULL;
    }

    void insertAtHead(int val) {
        Node* newNode = new Node(val);

        if(tail == NULL) {
            head = tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    void insertAtTail(int val) {
        Node* newNode = new Node(val);

        if(tail == NULL) {
            head = tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteAtHead() {
        if(head == NULL) return;
        else if(head == tail) {
            delete head;
            head = tail = NULL;
        } else {
            Node* temp = head;
            head = head->next;
            tail->next = head;

            temp->next = NULL;
            delete temp;
        }
    }

    void deleteAtTail() {
        if(head == NULL) return;
        else if(head == tail) {
            delete head;
            head = tail = NULL;
        } else {
            Node* temp = head;
            tail->next = NULL;
            
            while(temp->next != tail) {
                temp = temp->next;
            }
            
            delete tail;
            tail = temp;
            tail->next = head;
        }
    }

    void print() {
        if(head == NULL) {
            cout << "DLL is empty\n";
            return;
        }

        cout << head->data << "->";
        Node* temp = head->next;

        while(temp != head) {
            cout << temp->data << "->";
            temp = temp->next;
        }

        cout << temp->data << endl;
    }
};

int main(){
    CircularList cll;

    cll.insertAtHead(2);
    cll.insertAtHead(1);
    cll.insertAtTail(3);
    cll.insertAtTail(4);

    cll.deleteAtHead();
    cll.deleteAtTail();

    cll.print();
    return 0;
}