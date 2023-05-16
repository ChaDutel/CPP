#ifndef	BASE_HPP
# define BASE_HPP

# include <iostream>
# include <ctime>
# include <cstdlib>

class Base
{
	public:
		virtual ~Base();
};

Base::~Base(){}

class A : public Base {};
class B : public Base {};
class C : public Base {};

# endif
