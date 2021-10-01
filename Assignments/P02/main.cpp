#include<iostream>

using namespace std;

void foo(int, int);
void boo(int&, int);

int main()
{
	static int a = 1;
	int b = 3;
	 
	foo(a, b);
	boo(a, b);

	cout << "Now the value of A is " << a << " and the value of B is " << b << endl;
	return 0;
}

void foo(int x, int y)
{
	cout << "Now we are in the foo function\n";

	static int w = 3;
	x = x + w;
	y = y / 2;
	w = w * 3;

	cout << "The current values are as follows:\n";
	cout << "The value of X is: " << x << endl;
	cout << "The value of Y is: " << y << endl;
}

void boo(int& x, int y)
{
	cout << "In the function boo" << endl;

	static int w = 2;
	x = x - w;
	y = y * 2;
	w = w + 3;

	cout << "The values within boo are as follows:\n";
	cout << "The value of X is: " << x << endl;
	cout << "The value of Y is: " << y << endl;

	foo(x, y);
}