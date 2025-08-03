//you know basic object slicing..
/*
one more thing,we can point a child class pointer with parent class,
but reverse is not true..


Parent *p = new Child;:
This is valid in C++ because Child is derived from Parent, so a pointer to Child can be assigned to a pointer of type Parent. This is known as upcasting and is allowed without any explicit cast.

Child *c = new Parent;:
This is invalid because Parent is not derived from Child. A pointer to Parent cannot be implicitly converted to a pointer to Child. This is known as downcasting and requires an explicit cast, such as static_cast or dynamic_cast, and even then, it could result in undefined behavior if the cast is not valid.*/


#include <iostream>
#include <exception>

void testFunction(int code) {
    if (code == 1)
        throw std::runtime_error("Standard exception");
    else if (code == 2)
        throw 42; // Throwing an integer
    else
        throw "Unknown exception"; // Throwing a string literal
}

int main() {
    try {
        testFunction(1); // Change the argument to test different exceptions
    } 
    catch (...) {
        std::cout << "Caught an unknown exception!" << std::endl;
    } 
    catch (const std::exception& e) {
        std::cout << "Caught a standard exception: " << e.what() << std::endl;
    } 
    catch (int e) {
        std::cout << "Caught an integer exception: " << e << std::endl;
    }

    return 0;
}
