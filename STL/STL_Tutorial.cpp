#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <list>
// #include <deque>
// #include <stack>
// #include <queue>
// #include <map>
// #include <unordered_map>
// #include <set>
// #include <unordered_set>
// #include <algorithm>
using namespace std;

void Vector() {
    // vector is implemented as dynamic array
    vector<int> vec = {1, 2, 3, 4, 5};

    for(auto i = vec.begin(); i != vec.end(); i++){
        cout << *(i) << " ";
    }
    cout << endl;

    vector<int>::reverse_iterator it;
    
    for(it = vec.rbegin(); it != vec.rend(); it++){
        cout << *(it) << " ";
    }
    cout << endl;

    for(auto i = vec.rbegin(); i != vec.rend(); i++){
        cout << *(i) << " ";
    }
    cout << endl;

}

void List(){ 
    // list is implemented as a doubly linked list
    // size, erase, clear, begin, end, rbegin, rend, insert, front, and back all functions can be performed.
        list<int> l;

        l.emplace_back(1);
        l.push_back(2);
        l.push_front(3);
        l.push_front(5);

        l.pop_back();
        l.pop_front();

        for (int val : l){
            cout << val << " ";
        }
        cout << endl;
}

void Deque(){ 
        deque<int> d = {1, 2, 3, 4, 5};

        for (int val : d){
            cout << val << " ";
        }
        cout << endl;
}

void Pair(){
    pair<int, int> p = {1, 5};
    cout << p.first << endl;
    cout << p.second << endl;

    pair <string, int> M = {"priya", 077};
    cout << M.first << endl;
    cout << M.second << endl;

    pair <int, pair<string, int>> a = {1, {"Priya", 23}};
    cout << a.first << endl;
    cout << a.second.first << endl;
    cout << a.second.second << endl;

    vector<pair<int, int>> vec = {{1, 2}, {2, 3}, {3, 4}};
    vec.push_back({4, 5});
    vec.emplace_back(5, 6); // in-place objects create
    for(pair<int,int> p : vec){
        cout << p.first << " " << p.second << endl;
    }


}

void Stack(){
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    stack<int> s2;

    s2.swap(s);

    cout << "s size: " << s.size() << endl;
    cout << "s2 size: " << s2.size() << endl;

    // while(!s.empty()){
    //     cout << s.top() << " ";
    //     s.pop();
    // }

    cout << endl;
}

void Queue(){
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    queue<int> q2;

    q2.swap(q);

    cout << "q size: " << q.size() << endl;
    cout << "q2 size: " << q2.size() << endl;

    // while(!q.empty()){
    //     cout << q.front() << " ";
    //     q.pop();
    // }

    cout << endl;
}

void Priority_Queue(){
    priority_queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    priority_queue<int, vector<int>, greater<int>> q2;

    // q2.swap(q);

    // cout << "q size: " << q.size() << endl;
    // cout << "q2 size: " << q2.size() << endl;

    while(!q.empty()){
        cout << q.top() << " ";
        q.pop();
    }

    cout << endl;
}

void Map(){
    map<string, int> m; // here string is tupe of key while int is type of value
    m["TV"] = 50; // m[key] = value;
    m["Laptops"] = 100;
    m["Headphones"] = 150; // it will print in asc order of the starting character

    m.insert({"tablet", 120});
    m.emplace("watch", 40);
    m.erase("watch");

    for(auto p: m){
        cout << p.first << " " << p.second << endl;
    }

    if(m.find("camera") != m.end()){
        cout << "Camera found\n";
    }else {
        cout << "No camera found\n";
    }

    // cout << "Laptops count: " << m.count("Laptops") << endl;
    // cout << "Laptops = " << m["Laptops"] << endl;
}

void MultiMap(){
    multimap<string, int> m;

    m.emplace("tv", 100);
    m.emplace("tv", 100);
    m.emplace("tv", 100);
    m.emplace("tv", 10);
    m.emplace("tv", 150);

    // m.erase("tv"); // will erase all tv
    m.erase(m.find("tv")); // erase only one whose iterator comes

    for(auto p: m){
        cout << p.first << " " << p.second << endl;
    }

}

void Unordered_Map(){// O(1)

    unordered_map<string, int> m;

    m.emplace("tv", 100);
    m.emplace("laptop", 100);
    m.emplace("camera", 100);
    m.emplace("tv", 10);

    // m.erase("tv"); // will erase all tv
    // m.erase(m.find("tv")); // erase only one whose iterator comes

    for(auto p: m){
        cout << p.first << " " << p.second << endl;
    }

}

void Set(){// It also have Multi set and Unordered set like the ones in Map
    set<int> s;

    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    s.insert(1);
    s.insert(2);
    s.insert(3);

    cout << "Size: " << s.size() << endl;
    cout << "Lower bound of 4 : " << *(s.lower_bound(4))<< endl;
    cout << "Upper bound of 4 : " << *(s.upper_bound(4))<< endl;

    for(auto val : s){
        cout << val << " ";
    }
    cout << endl;
}

bool comparator(pair<int, int> p1, pair<int, int> p2){
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;

    if(p1.first < p2.first) return true;
    else return false;
}

void Algorithms(){
    vector<int> arr = {6, 2, 5, 6, 9};
    vector<pair<int, int>> vec = {{5, 3}, {2, 4}};

    // sort(arr.begin(), arr.end());
    // sort(arr.begin(), arr.end(), greater<int>());
    sort(vec.begin(), vec.end(), comparator);
    reverse(arr.begin(), arr.end());

    string s = "abc";
    next_permutation(s.begin(), s.end());
    prev_permutation(s.begin(), s.end());
    cout << s << endl;

    for(auto p : vec){
        cout << p.first << " " << p.second << endl;
    }

}

int main(){
    // cout << "Vector" << endl;
    // Vector();

    // cout << "List" << endl;
    // List();

    // cout << "Deque" << endl;
    // Deque();

    // cout << "pair" << endl;
    // Pair();

    // cout << "Stack" << endl;
    // Stack();

    // cout << "Queue" << endl;
    // Queue();

    // cout << "Priority Queue" << endl;
    // Priority_Queue();

    // cout << "Map" << endl;
    // Map();

    // cout << "Multi Map" << endl;
    // MultiMap();

    // cout << "Unordered Map" << endl;
    // Unordered_Map();

    // cout << "Set" << endl;
    // Set();

    cout << "Algorithms" << endl;
    Algorithms();

    return 0;
}