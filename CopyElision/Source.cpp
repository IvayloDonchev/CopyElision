#include <iostream>

struct Foo {
	Foo() { std::cout << this << " Constructed" << std::endl; }
	Foo(const Foo &) { std::cout << this << " Copy-constructed" << std::endl; }
	Foo(Foo &&) { std::cout << this << " Move-constructed" << std::endl; }
	~Foo() { std::cout << this << " Destructed" << std::endl; }
};

Foo f() 
{
	Foo foo;
	return foo;
}

void ff()
{
	Foo foo;
	throw foo;
}

void f(Foo f)
{
	std::cout << "Fn" << std::endl;
}

//Трябва да се компилира първо в debug, после в release
int main() 
{
	Foo foo = f();
	std::cout << std::endl;

	f(Foo());
	std::cout << std::endl;

	try {
		ff();
	}
	catch (Foo foo) {
		std::cout << "Catch" << std::endl;
	}
}