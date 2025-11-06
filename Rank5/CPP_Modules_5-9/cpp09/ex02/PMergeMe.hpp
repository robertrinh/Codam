#pragma once

#include <vector>
#include <deque>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <chrono>
#include <stdexcept>
#include <cstdlib>

class PmergeMe {
private:
    std::vector<int> _data;
    
    static std::chrono::time_point<std::chrono::high_resolution_clock> getTime();
    bool isValidNumber(const std::string& str);
    void parseInput(char** argv);

    //* Jacobsthal sequence
    static size_t jacobsthal(size_t n);
    static std::vector<size_t> generateJacobsthalSequence(size_t n);
	void displayBefore() const;
    void displayAfter() const;

    //* template implementations for Ford-Johnson algorithm
    template<typename Container>
    void fordJohnson(Container& arr);

    template<typename Container>
    void insertionSort(Container& arr, size_t left, size_t right);
    
    template<typename Container>
    size_t binarySearch(const Container& arr, int value, size_t end);
public:
    PmergeMe() = default;
    PmergeMe(const PmergeMe& other) = delete;
    PmergeMe& operator=(const PmergeMe& other) = delete;
    ~PmergeMe() = default;
    
    void processInput(char** argv);
};

template<typename Container>
size_t PmergeMe::binarySearch(const Container& arr, int value, size_t end) {
    size_t left = 0;
    size_t right = end;
    
    while (left < right)
	{
        size_t mid = left + (right - left) / 2;
        if (arr[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

template<typename Container>
void PmergeMe::fordJohnson(Container& arr) {
    size_t n = arr.size();
    
    if (n <= 1)
        return;
    
    //* step 1: pair elements and sort pairs
    std::vector<std::pair<int, int> > pairs;
    bool hasRemainder = (n % 2 == 1);
    int remainder = hasRemainder ? arr[n - 1] : 0;
    size_t pairCount = n / 2;
    
    for (size_t i = 0; i < pairCount; i++) 
	{
        int a = arr[2 * i];
        int b = arr[2 * i + 1];
        if (a > b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }
    
    //* step 2: sort pairs by their larger element (recursively)
    Container largerElements;
    for (size_t i = 0; i < pairs.size(); i++)
        largerElements.push_back(pairs[i].first); 
    fordJohnson(largerElements);
    
    //* reorder pairs based on sorted larger elements
    std::vector<std::pair<int, int> > sortedPairs;
    for (size_t i = 0; i < largerElements.size(); i++) 
	{
        for (size_t j = 0; j < pairs.size(); j++) 
		{
            if (pairs[j].first == largerElements[i]) 
			{
                sortedPairs.push_back(pairs[j]);
                pairs[j].first = -1; //* mark as used
                break;
            }
        }
    }
    
    //* step 3: create main chain and pend elements
    Container mainChain;
    Container pend;
    
    //* first small element goes into pend
    if (!sortedPairs.empty()) 
	{
        pend.push_back(sortedPairs[0].second);
        mainChain.push_back(sortedPairs[0].first);
    }
    
    //* all larger elements go into main chain
    for (size_t i = 1; i < sortedPairs.size(); i++) 
	{
        mainChain.push_back(sortedPairs[i].first);
        pend.push_back(sortedPairs[i].second);
    }
    
    //* step 4: insert pend elements using Jacobsthal sequence
    if (!pend.empty()) 
	{
        //* first pend element is always inserted at beginning
        size_t pos = binarySearch(mainChain, pend[0], mainChain.size());
        mainChain.insert(mainChain.begin() + pos, pend[0]);
        
        //* generate Jacobsthal sequence for remaining elements
        std::vector<size_t> jacSequence = generateJacobsthalSequence(pend.size());
        std::vector<bool> inserted(pend.size(), false); //* track inserted elements
        inserted[0] = true;
        
        //* insert elements at Jacobsthal indices
        for (size_t i = 0; i < jacSequence.size(); i++) 
		{
            size_t jacIdx = jacSequence[i];
            if (jacIdx < pend.size() && !inserted[jacIdx]) 
			{
                pos = binarySearch(mainChain, pend[jacIdx], mainChain.size());
                mainChain.insert(mainChain.begin() + pos, pend[jacIdx]);
                inserted[jacIdx] = true;
            }
            
            //* insert elements between previous and current Jacobsthal number
            size_t prevJac = (i == 0) ? 1 : jacSequence[i - 1];
            for (size_t j = jacIdx - 1; j > prevJac && j < pend.size(); j--) 
			{
                if (!inserted[j]) 
				{
                    pos = binarySearch(mainChain, pend[j], mainChain.size());
                    mainChain.insert(mainChain.begin() + pos, pend[j]);
                    inserted[j] = true;
                }
            }
        }
        
        //* insert remaining elements not covered by Jacobsthal
        for (size_t i = 1; i < pend.size(); i++) 
		{
            if (!inserted[i]) {
                pos = binarySearch(mainChain, pend[i], mainChain.size());
                mainChain.insert(mainChain.begin() + pos, pend[i]);
            }
        }
    }
    
    //* insert remainder if exists
    if (hasRemainder) 
	{
        size_t pos = binarySearch(mainChain, remainder, mainChain.size());
        mainChain.insert(mainChain.begin() + pos, remainder);
    }
    arr = mainChain;
}
