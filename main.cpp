#include <iostream>
#include "mr_shared_ptr.h"

struct Foo {
    Foo(): a(2) {};
    int a;
    void print_a() {
        std::cout << "a value is: " << a << std::endl;
    }
};

int main(int argc, char** argv) {
    shared_ptr<int> ptr1(new int);

    if(ptr1) {
        std::cout << "Ptr1 is not null" << std::endl; 
    } else {
        std::cout << "Ptr1 is null" << std::endl; 
    }
    
    {
        shared_ptr<int> ptr2;
        shared_ptr<int> ptr3;
        shared_ptr<int> ptr4 = ptr1;
        ptr2 = ptr1;
        ptr3 = ptr1;

        std::cout << "Number of instances: " << ptr2.use_count() << std::endl;
    }
    
    std::cout << "Number of instances: " << ptr1.use_count() << std::endl;
    
    shared_ptr<int> ptr5 = ptr1;
    std::cout << "Number of instances: " << ptr1.use_count() << std::endl;

    ptr5.reset();
    std::cout << "Number of instances: " << ptr1.use_count() << std::endl;

    *ptr1 = 13;
    std::cout << "Resource value: " << *ptr1 << std::endl;

    ptr1.reset();
    std::cout << "Number of instances: " << ptr1.use_count() << std::endl;

    shared_ptr<Foo> foo_ptr(new Foo());
    (*foo_ptr).print_a();
    foo_ptr->print_a();

    return 0;
}
