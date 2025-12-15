#include <iostream>
#include <string>
using namespace std;

bool IsPalindrome(string str){
    string temp = str ;
    int s = 0, e = str.length()-1;

    while(s < e){
        swap(str[s++], str[e--]);
    }

    if(str == temp) {
        return true;
    } else {
        return false;
    }
}

bool isPalinDrome(string s) {
    int st = 0, end = s.length() - 1;
    while (st < end) {
        if(s[st++] != s[end--]) {
            return false;
        }
    }
    return true;
}

int main(){
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    
    if(IsPalindrome(s)){
        cout << s << " is Pallindrome" << endl;
    } else{
        cout << s << " is not Palindrome" << endl;
    }

     if(isPalinDrome(s)){
        cout << s << " is Pallindrome" << endl;
    } else{
        cout << s << " is not Palindrome" << endl;
    }


    return 0;
}