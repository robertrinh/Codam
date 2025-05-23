#include "Base.hpp"

int main()
{
    //* test multiple random generations
    for (int i = 0; i < 5; i++) {
        std::cout << "Test " << i + 1 << ":" << std::endl;
        Base* ptr = generate();
        if (!ptr) {
            std::cout << "Failed to generate object" << std::endl;
            continue;
        }
        
        std::cout << "Pointer identification: ";
        identify(ptr);
        
        std::cout << "Reference identification: ";
        identify(*ptr);
        
        std::cout << std::endl;
        delete ptr;
    }
    
    return 0;
}
