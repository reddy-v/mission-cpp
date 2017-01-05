#pragma once
#include <iostream>
template <typename T>
class Item24UniversalRefvsRvalueref
{
public:
	// Universal reference function, because it has own type deduction
	// Accepts all values 
	template <typename T1> 
	void print(T1&& x);

	// rvalue reference function cannot bind lvalue params, params accepted -- 3, "Hello" std::move(x)
	void print(T&& x);

	// rvalue reference function bind to rvalue const parameters
	void print(const T&& x);
	static void Test();
	Item24UniversalRefvsRvalueref();
	~Item24UniversalRefvsRvalueref();
};

template <typename T>
template <typename T1>
void Item24UniversalRefvsRvalueref<T>::print(T1&& x)
{
	std::cout << x << std::endl;
	std::cout << typeid(x).name() << std::endl;
}

template <typename T>
void Item24UniversalRefvsRvalueref<T>::print(T&& x)
{
	std::cout << x << std::endl;
	x = x + 10;
}

template <typename T>
void Item24UniversalRefvsRvalueref<T>::print(const T&& x)
{
	std::cout << "From const " << std::endl;
}

template <typename T>
void Item24UniversalRefvsRvalueref<T>::Test()
{
		const int x = 10;
		int y = 20;
		auto s = "Kill";
		float f = 10.04;
		Item24UniversalRefvsRvalueref<int> a;
		//a.print<std::string>("Hello"); // rvalue param call
		a.print(x); // lvalue param pass
		a.print(std::move(x)); // make it definitely rvalue const
		a.print(std::move(y)); // make it definitely rvalue 

		std::cout << y << std::endl;
		y = y * 10;
		a.print(s); // lvalue string pass
		std::cout << s << std::endl;
}

template <typename T>
Item24UniversalRefvsRvalueref<T>::Item24UniversalRefvsRvalueref()
{
}

template <typename T>
Item24UniversalRefvsRvalueref<T>::~Item24UniversalRefvsRvalueref()
{
}
