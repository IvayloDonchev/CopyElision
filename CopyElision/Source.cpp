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


//������ �� �� ��������� ����� � debug, ����� � release
int main() 
{
	Foo foo = f();
}