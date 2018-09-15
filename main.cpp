#include <iostream>
#include "mr_shared_ptr.h"

int main(int argc, char** argv) {
    shared_ptr<int> ptr1;
    
    {
        shared_ptr<int> ptr2;
        shared_ptr<int> ptr3;
        shared_ptr<int> ptr4 = ptr1;
        ptr2 = ptr1;
        ptr3 = ptr1;

        std::cout << "Number of instances: " << ptr4.use_count() << std::endl;
    }
    
    std::cout << "Number of instances: " << ptr1.use_count() << std::endl;

    return 0;
}
