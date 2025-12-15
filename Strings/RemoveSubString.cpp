// Leetcode 1910
// 1910. Remove All Occurrences of a Substring
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while( s.length() > 0 && s.find(part) < s.length()) {
            s.erase( s.find(part), part.length());
        }
        return s;
    }
};

int main(){
    Solution sol;
    string s, part;
    cout << "Enter string: ";
    getline(cin, s);
    
    cout << "part: ";
    getline(cin, part);

    cout << "After removing:  " << sol.removeOccurrences(s, part) << endl;
    return 0;
}