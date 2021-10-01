//****************************************************************************
//			Assignment #5													 *
//			Name: Loic Konan												 *
//			Data Structures: 11/13/2020										 *
//																			 *
//****************************************************************************
/*****************************************************************************
	This program will contain 2  function that will produce the desired      *
	outcome by recursively calling itself and either returning a result or	 *
	displaying the results each time it is called.							 *
	Both Functions MUST BE recursive functions (direct recursion only) that	 *
	will solve the following problems.										 *
																			 *
		A) Function 1 (Name: Summation). It will ask for a number "n1",		 *
		where n1 > 0, and it will compute the summation of all odd integers	 *
		numbers between 1 and n1.											 *
		b) Function 2 (Name: BaseExponent). It will ask for two numbers,	 *
		base and exponent. It will then compute baseexponent recursively,	 *
		examples 2^12; 10^4, etc.											 *
																			 *
	None of the functions can use repetitive structures such as for or while *
	loops, ect.																 *
																			 *
*****************************************************************************/

#include<iostream>
#include<cmath>

using namespace std;

// Will compute the summation of all odd integers numbers between 1 and n1.
int Summation(long int);

// It will then compute base exponent recursively.
int BaseExponent(int, int);

int main()
{
	int long number;
	int base, exponent;

	cout << "\t\t|=============================================|\n";
	cout << "\t\t|                                             |\n";
	cout << "\t\t|               WELCOME To Loic               |\n";
	cout << "\t\t|           Calculator For The Summation      |\n";
	cout << "\t\t|         Of Odd Numbers and Base Exponents   |\n";
	cout << "\t\t|                                             |\n";
	cout << "\t\t|=============================================|\n\n";

	cout << "\t\tPlease enter an integer number: ";
	cin  >> number;

	cout << "\n\t\tThe Summation of the odd integers between 1 and "
		 << number << " is: " << Summation(number) << "\n\n";

	cout << "\t\tNow, Please enter the base and the exponent: ";
	cin >> base >> exponent;

	cout << "\n";
	cout << "\t\t\t\t" << base << "^"    << exponent << " = " 
		 << BaseExponent(base, exponent) << "\n";

	return 0;
}



/******************************************************************************
	Function Name: Summation												  *
	Paramters: int number													  *
																			  *
	This function receives one integer and the function will recursively	  *
	call itself until the number is no longer greater than 0.				  *
	While this is taking place a running total is kept of the summation		  *
	of the odd numbers between 1 and the number received from the user.		  *
	Once this has completed the value is returned and displayed on the screen.*
																			  *
*******************************************************************************/
int Summation(long int number)
{
	static long int total = 0;

	if (number > 0)
	{
		// Odd Numbers.
		if (number % 2 == 0)
		{
			Summation(number - 1);
		}

		// Even Numbers.
		else
		{
			total += number;
			Summation(number - 1);
		}
	}
	return total;
}


/******************************************************************************
	Function Name: BaseExponent												  *
	Paramters: int base, int exponent										  *
																			  *
	This function receives two integers. The function will compute the base   *
	exponent and then the function will recursively call itself as it		  *
	decreases the power and stop when it is not greater than 0 then return    *
	the value back to Main.													  *
																			  *
******************************************************************************/
int BaseExponent(int base, int exponent)
{
	if (exponent > 0)
	{
		return (base*BaseExponent(base, exponent - 1));
	}
	else
		return 1;
}
