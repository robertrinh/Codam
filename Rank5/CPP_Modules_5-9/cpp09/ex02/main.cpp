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


// #include <sstream>
// #include <vector>

// void runTest(const std::string& testName, const std::vector<std::string>& args) {
//     std::cout << "\n=== " << testName << " ===" << std::endl;
//     std::vector<char*> argv;
//     argv.push_back((char*)"./PmergeMe");
//     for (size_t i = 0; i < args.size(); i++)
//         argv.push_back((char*)args[i].c_str());
//     argv.push_back(NULL);
//     try {
//         PmergeMe sorter;
//         sorter.processInput(&argv[0]);
//     } catch (const std::exception& e) {
//         std::cerr << "Error: " << e.what() << std::endl;
//     }
// }

// int main() {
//     //* standard test (5 elements)
//     runTest("Standard (5 elements)", {"3", "5", "9", "7", "4"});

//     //* large numbers
//     runTest("Large numbers", {"2147483647", "2147483646", "1000000000", "999999999"});

//     //* 3000 elements (simulating shuf)
//     std::vector<std::string> large;
//     for (int i = 0; i < 3000; i++) {
//         std::ostringstream oss;
//         oss << ((i * 48271 + 12345) % 100000 + 1);
//         large.push_back(oss.str());
//     }
//     runTest("3000 elements", large);

//     //* error cases
//     runTest("Error: Negative", {"-1", "2"});
//     runTest("Error: Non-numeric", {"abc", "123"});
//     runTest("Error: Overflow", {"2147483648"});
    
//     std::cout << "\n=== Error: Empty ===" << std::endl;
//     try {
//         char* argv[] = {(char*)"./PmergeMe", NULL};
//         PmergeMe sorter;
//         sorter.processInput(argv);
//     } catch (const std::exception& e) {
//         std::cerr << e.what() << std::endl;
//     }

//     return EXIT_SUCCESS;
// }