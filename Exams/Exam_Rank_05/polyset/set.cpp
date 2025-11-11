#include "set.hpp"

set::set(searchable_bag& bag) : _bag(bag) {}

set::set(const set& src) : _bag(src._bag) {}

set& set::operator=(const set& src)
{
    (void)src;
    return *this;
}

set::~set() {}

void set::insert(int value)
{
    if (!_bag.has(value))
    _bag.insert(value);
}

void set::insert(int *array, int size)
{
    for (int i = 0; i < size; i++)
        _bag.insert(array[i]);
}

void set::print() const
{
    _bag.print();
}

void set::clear()
{
    _bag.clear();
}

bool set::has(int value) const
{
    return (this->_bag.has(value));
}

searchable_bag& set::get_bag()
{
    return this->_bag;
}
