#include <iostream>
#include <vector>
using namespace std;

int LinearSearch(vector<int>vec, int num){
    for (int i  = 0; i < vec.size(); i++ ){
       if ( vec[i] == num ){
        return i;
       }
    }
    return -1;
}

int main(){
    int num;
    vector<int> vec;

    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    cout << "Enter element you want to search ";
    cin >> num;

    cout << "Element is at index: " << LinearSearch(vec, num) << endl;

    return 0;
}