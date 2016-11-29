#include <iostream>

struct Foo {
	Foo() { std::cout << "Constructed" << std::endl; }
	Foo(const Foo &) { std::cout << "Copy-constructed" << std::endl; }
	Foo(Foo &&) { std::cout << "Move-constructed" << std::endl; }
	~Foo() { std::cout << "Destructed" << std::endl; }
};

Foo f() 
{
	Foo foo;
	return foo;
}


//Трябва да се компилира първо в debug, после в release
int main() 
{
	Foo foo = f();
}