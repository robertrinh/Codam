#include "PmergeMe.hpp"

std::chrono::time_point<std::chrono::high_resolution_clock> PmergeMe::getTime() {
    return std::chrono::high_resolution_clock::now();
}

/**
 * @brief Generate the nth Jacobsthal number
 * @param n the index of the Jacobsthal number to generate
 * @details Jacobsthal sequence: Each number = previous + (2 * previous of previous)
 * @details example: jacobsthal(3) = 1 + (2 * 0) = 1
 * @return the nth Jacobsthal number
 */
size_t PmergeMe::jacobsthal(size_t n) {
	size_t a = 0, b = 1;

	if (n == 0) 
		return 0;
    if (n == 1) 
		return 1;
    for (size_t i = 2; i <= n; i++) 
	{
		size_t temp = b;
		b = b + 2 * a;
		a = temp;
    }
    return b;
}

std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n) {
    std::vector<size_t> sequence;
    size_t idx = 3; //* start from 3 because jacobsthal(0) = 0 and jacobsthal(1) = 1
    
    while (jacobsthal(idx) < n) 
	{
        size_t jac = jacobsthal(idx);
        sequence.push_back(jac);
        idx++;
    }
    return sequence;
}

bool PmergeMe::isValidNumber(const std::string& str) {
    if (str.empty() || (str[0] == '-' || str[0] == '+'))
        return false;
    
    for (size_t i = 0; i < str.length(); i++) 
	{
        if (!isdigit(str[i]))
            return false;
    }
    
    //* check for overflow
    std::stringstream ss(str);
    long long num;
    ss >> num;
    if (num < 0 || num > 2147483647)
        return false;
    return true;
}

void PmergeMe::parseInput(char** argv) {
    for (int i = 1; argv[i] != NULL; i++) 
	{
        std::string arg(argv[i]);

        if (!isValidNumber(arg))
            throw std::runtime_error("Error: Invalid input");
        int num = std::atoi(arg.c_str());
        _data.push_back(num);
    }
    
    //* duplicates check
    std::vector<int> temp = _data;
    std::sort(temp.begin(), temp.end());
    for (size_t i = 1; i < temp.size(); i++) 
	{
        if (temp[i] == temp[i - 1])
            throw std::runtime_error("Error: Duplicate numbers");
    }
}

void PmergeMe::displayBefore() const {
    std::cout << "Before: ";
    for (size_t i = 0; i < _data.size() && i < 5; i++)
        std::cout << _data[i] << " ";
    if (_data.size() > 5)
        std::cout << "[...]";
    std::cout << std::endl;
}

void PmergeMe::displayAfter() const {
    std::cout << "After:  ";
    for (size_t i = 0; i < _data.size() && i < 5; i++)
        std::cout << _data[i] << " ";
    if (_data.size() > 5)
        std::cout << "[...]";
    std::cout << std::endl;
}

void PmergeMe::processInput(char** argv) {   
	parseInput(argv);
    if (_data.empty())
        throw std::runtime_error("Error: No valid numbers provided");

    displayBefore();
    std::vector<int> vectorData(_data.begin(), _data.end());
    auto startVec = getTime();
    fordJohnson(vectorData);
    auto endVec = getTime();
    auto timeVec = std::chrono::duration<double, std::micro>(endVec - startVec).count();
    
    std::deque<int> dequeData(_data.begin(), _data.end());
    auto startDeq = getTime();
    fordJohnson(dequeData);
    auto endDeq = getTime();
    auto timeDeq = std::chrono::duration<double, std::micro>(endDeq - startDeq).count();
    
    //* update internal data with sorted result (for displayAfter)
    _data = vectorData;
    displayAfter();
    std::cout << "Time to process a range of " << vectorData.size() 
              << " elements with std::vector : " << std::fixed << std::setprecision(5) 
              << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << dequeData.size() 
              << " elements with std::deque  : " << std::fixed << std::setprecision(5) 
              << timeDeq << " us" << std::endl;
}
