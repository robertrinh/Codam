#pragma once

#include "searchable_bag.hpp"

class set 
{
private:
    searchable_bag& _bag;
public:
    set(searchable_bag& bag);
    set(const set& src);
    set& operator=(const set& src);
    ~set();

    void insert(int value);
	void insert(int *array, int value);
	void print() const;
	void clear();

    bool has(int value) const;
    searchable_bag& get_bag();
};