#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

class Base{
public:
	virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate();
void identify(Base* p);
void identify(Base& p);


