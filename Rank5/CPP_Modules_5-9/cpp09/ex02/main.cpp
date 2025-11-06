#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: Provide at least one positive integer as argument." << std::endl;
        return EXIT_FAILURE;
    }
    try {
        PmergeMe sorter;
        sorter.processInput(argv);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}