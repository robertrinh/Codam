#include "Base.hpp"

int main()
{
    //* test multiple random generations
    for (int i = 0; i < 5; i++) {
        std::cout << "Test " << i + 1 << ":" << std::endl;
        
        //* generate random object
        Base* ptr = generate();
        if (!ptr) {
            std::cout << "Failed to generate object" << std::endl;
            continue;
        }
        
        //* test pointer identification
        std::cout << "Pointer identification: ";
        identify(ptr);
        
        //* test reference identification
        std::cout << "Reference identification: ";
        identify(*ptr);
        
        std::cout << std::endl;
        
        //* clean up
        delete ptr;
    }
    
    return 0;
}
