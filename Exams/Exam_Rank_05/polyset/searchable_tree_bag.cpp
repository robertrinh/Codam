#include "searchable_tree_bag.hpp"

bool searchable_tree_bag::has(int value) const
{
    return (search_value(value, this->tree));
}

bool searchable_tree_bag::search_value(int value, node *n) const
{
	if (!n)
		return false;
    if (value == n->value)
        return true;
    if (value < n->value && n->l)
        return (search_value(value, n->l));
    if (value > n->value && n->r)
        return (search_value(value, n->r));
    return false;
}