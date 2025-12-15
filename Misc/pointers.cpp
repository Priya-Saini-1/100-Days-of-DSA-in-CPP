// memory address
// pointers; ptr to ptr
// dereferencing
// pass by : ptrs and reference (alias)
// array pointers
// pointer arithmatics
// & uses for bitwise or , addresss of and alias
// * uses for multiply and dereference

#include <iostream>
#include <vector>
using namespace  std;

int main(){
    int a = 5;
    int* ptr = &a;
    int** ptr2 = &ptr;
    cout << a << " has address: " << &a << endl;
    return 0;
}