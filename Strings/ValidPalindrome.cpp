// Leetcode 125
#include <iostream>
#include <string>
#include <cctype> // Required for isalnum()
using namespace std;

bool isAlphaNumeric(char ch) { // It is also an inbuilt function in c++ function is : isalnum(ch1)
    if ( ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9'){
        return true;
    }
    return false;
}

bool isPalinDrome(string s) {
    int st = 0, end = s.length() - 1;
    while (st < end) {
        if(!isalnum(s[st])) {
            st++;
            continue;
        }

        if(!isAlphaNumeric(s[end])) {
            end--;
            continue;
        }

        if(tolower(s[st]) != tolower(s[end])) {
            return false;
        }
        st++; end--;
    }
    
    return true;
}

int main(){
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

     if(isPalinDrome(s)){
        cout << s << " is Pallindrome" << endl;
    } else{
        cout << s << " is not Palindrome" << endl;
    }


    return 0;
}