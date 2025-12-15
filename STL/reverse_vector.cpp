#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec;

    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    cout << "Before Reverse" << endl;
    for (int i  = 0; i < vec.size(); i++ ){
        cout << "vec " << i+1 << " = " << vec[i] << endl;
    }

    cout << "After Reverse" << endl;
    for (int i = vec.size();  i  > 0; i--) {
        cout << "vec " << (vec.size() - i)+1 << " = " << vec[i-1] << endl;
    }

    return 0;
}