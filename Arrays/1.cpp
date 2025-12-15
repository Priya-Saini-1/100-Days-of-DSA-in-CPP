#include<iostream>
#include<string>
using namespace std;

class Teacher {
    //properties/ attributes
private:
    double salary;
public:
    Teacher() {
        dept = "AI & DS";
    }
    string name;
    string dept;
    string subject;
    

    //methods/ member func.
    void changeDept (string newDept) {
        dept = newDept;
    }

    //setter
    void setSalary (double s) {
        salary = s;
    }
    //getter
    double getSalary() {
        return salary;
    }
};

//    Encapculation
//       class Account {
//         private:
//             double balance;
//             string password; // data hiding
//         public:
//             string accountId;
//             string username;
//     }

// };

int main() {
    Teacher t1;// Constructor calls
    t1.name = "Priya";
    t1.subject = "C++";
    t1.setSalary(250000);
    
    cout << t1.name << endl;
    cout << t1.subject << endl;
    cout << t1.dept << endl;
    cout << t1.getSalary() << endl;
    return 0;
}
