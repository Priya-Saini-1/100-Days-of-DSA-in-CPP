#include <iostream>
using namespace std;

int fib(int n) { // TC = O ( 2 ^ n)
        if (n == 0 || n == 1){
            return n;
        }

        return fib(n-1) + fib(n-2);
    }

int main(){
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "The term on  " << n << " is " << fib(n) << endl;
    return 0;
}