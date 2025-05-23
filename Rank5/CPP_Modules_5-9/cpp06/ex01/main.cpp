#include "Serializer.hpp"

int main() {
    //* creating a data object with some values
    Data data = {42, "test data"};
    Data* originalPtr = &data;

    std::cout << "Original Data values:" << std::endl;
    std::cout << "Value: " << originalPtr->value << std::endl;
    std::cout << "Name: " << originalPtr->name << std::endl;
    std::cout << "Original pointer address: " << originalPtr << std::endl;
    std::cout << std::endl;

    //* serializing the pointer to uintptr_t
    uintptr_t serialized = Serializer::serialize(originalPtr);
    std::cout << "Serialized value: " << serialized << std::endl;
    std::cout << std::endl;

    //* deserializing back to a pointer
    Data* deserializedPtr = Serializer::deserialize(serialized);
    std::cout << "Deserialized pointer address: " << deserializedPtr << std::endl;
    std::cout << "Deserialized Data values:" << std::endl;
    std::cout << "Value: " << deserializedPtr->value << std::endl;
    std::cout << "Name: " << deserializedPtr->name << std::endl;
    std::cout << std::endl;

    if (originalPtr == deserializedPtr)
        std::cout << "Success: Original and deserialized pointers are equal!" << std::endl;
    else
        std::cout << "Error: Pointers are not equal!" << std::endl;

    return 0;
}
