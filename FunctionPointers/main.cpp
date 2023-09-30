#include <iostream>
using std::cin;
using std::cout;
using std::endl;

const char* Hello()
{
	return "Hello";
}
int Sum(int a, int b)
{
	return a + b;
}

void main()
{
	setlocale(LC_ALL, "");
	cout << Hello << endl;		// Адрес функции
	const char* (*pHello)() = Hello;
	cout << pHello << endl;		// Адрес той же функции, сохраненный в указателе
	cout << pHello() << endl;	// Вызов функции 'Hello()' через указатель 'pHello'

	cout << Sum(2, 3) << endl;
	cout << Sum << endl;
	int (*pSum)(int, int) = Sum;
	cout << pSum << endl;
	cout << pSum(2, 3) << endl;
}