// Eulid's Algorithm
#include <iostream>
using namespace std;

int gcd(int a, int b){
    while(a > 0 && b > 0){
        if(a > b){
            a = a % b;
        } else {
            b = b % a;
        }
    }

    if(a == 0) return b;
    return a;
}

int gcdRec(int a, int b){
    if(b == 0) return a;

    return gcdRec(b, a % b);
}

// a * b = LCM(a, b) * GCD(a,b)
int LCM(int a, int b){
    return (a*b) / gcdRec(a, b);
}

int main(){
    cout << "GCD (normal)" << endl;
    cout << gcd(20, 28) << endl;
    cout << gcd(6, 12) << endl;
    cout << gcd(0, 8) << endl;

    cout << "GCD by recursion" << endl;
    cout << gcdRec(20, 28) << endl;
    cout << gcdRec(6, 12) << endl;
    cout << gcdRec(0, 8) << endl;

    cout << "LCM (by GCD recursion method)" << endl;
    cout << LCM(20, 28) << endl;
    cout << LCM(6, 12) << endl;
    cout << LCM(0, 8) << endl;
    return 0;
}