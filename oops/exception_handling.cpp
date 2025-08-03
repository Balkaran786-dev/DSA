#include <iostream>
using namespace std;

class Test {
public:
    Test(const string& name) : name(name) {
        cout << "Constructing " << name << endl;
    }
    ~Test() {
        cout << "Destructing " << name << endl;
    }

private:
    string name;
};

void func2() {
    Test t2("Object in func2");
    throw runtime_error("Exception in func2"); // Exception thrown
    
}

void func1() {
    Test t1("Object in func1");
    func2(); // func2 is called
}

int main() {
    try {
        func1(); // func1 is called
    } catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    return 0;
}

