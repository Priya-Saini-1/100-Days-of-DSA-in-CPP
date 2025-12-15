#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

class Stack { // using array
    vector<int> v;
    public:
        void push(int val){
            v.push_back(val);
        }

        void pop(){
            v.pop_back();
        }

        int top() {
            return v[v.size()-1];
        }

        bool empty(){
            return v.size()== 0;
        }
};

class Stack_ll { // using linked list
    list<int> ll;
    public:
        void push(int val){
           ll.push_front(val);
        }

        void pop(){
            ll.pop_front();
        }

        int top() {
            return ll.front();
        }

        bool empty(){
            return ll.size()== 0;
        }
};

int main(){
    Stack_ll s; // stack with ll
    Stack s1; // stack by array or vector
    stack<int> s3; // stack inbuilt in stl
    s.push(10);
    s.push(20);
    s.push(30);

    while (!s.empty())
    {
        cout<< s.top()<< " ";
        s.pop();
    }
    
    return 0;
}