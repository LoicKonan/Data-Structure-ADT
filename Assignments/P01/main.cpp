//***************************************************************************
//						Assignment #1										*
//						Name: Loic Konan									*
//						Data Structures: 09/20/2020							*
//																			*
//***************************************************************************
//		The intent of this program is to compute �x� the root(s) of a		*
//		quadratic equation using the quadratic formula.  �a� �b� and �c�	*
//		will be entered in by the user. We will only solve 3 equations,		*
//		but this code is designed to accept larger problem sizes by			*
//		accepting only one modification. This program content 6 different	*
//      function to make it more manageable. These separate functions		*
//		calculate the needed variables such as the Discriminant, numerator, * 
//		denominator and the root(s) values. These are then plugged into		*
//      the Quadratic Equation to solve the problem.						*
//***************************************************************************
//		To run the program the user needs to launch the program and         *
//		follow the prompts such as entering 3 integer number followed by a  *
//		space 3 times to display the Results								*
//																			*
//***************************************************************************


#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

const int rows = 3; // Global Size Variable for Rows
const int cols = 3; // Global Size Variable for Columns

// Prototypes for the Functions below.
void myMatrix();
void valueOfDiscriminant(int array[rows][cols]);
void valueOfNumerator(int array[rows][cols], int[]);
void valueOfDenominator(int array[rows][cols], int[], double[], double[]);
void printRoots(int array[rows][cols], int[], double[], double[], int[]);
void showMeTheMatrix(int array[rows][cols], int[], double[], double[], int[],
						double[], double[]);


int main()
{
	// Calling the function myMatrix.
	myMatrix();
}


//***************************************************************************
//					Function Name: MyMatrix () 								*
//					Parameters: No initial parameters.						*
//																			*
//		The function is creating and initializing a 3D array with the		*
//		dimensions already determined by our global variables.				*		
//		The user is prompted to enter 3 integer numbers 3 times a, b, c		*
//		followed by a space.												*
//																			*
//***************************************************************************


void myMatrix()
{
	int ABCMatrix[rows][cols];

	// Loop to store the user input data in the Array ABCMatrix.
	for (int i = 0; i < rows; i++)
	{
		// Prompt the user for number a,b,c.
		cout << "Please enter 3 numbers a,b,c 3 times: \n";
		cin >> ABCMatrix[i][0] >> ABCMatrix[i][1] >> ABCMatrix[i][2];
	}
	cout << '\n';

	valueOfDiscriminant(ABCMatrix);
}


//*******************************************************************************
//				Function Name: ValueofDiscriminant()							*
//				Parameters: 3D Array is passed.									*
//																				*
//		The function receives the array and uses a for loop and a counter		*
//		variable to calculate and stores the value of the Discriminant			*
//		in a 1D array set to the same index as our global variable rows.		*
//		The Formula for the Discriminant is: (b*b)-(4*a*c)						*
//																				*
//*******************************************************************************


void valueOfDiscriminant(int array[rows][cols])
{
	int discriminant[rows];

	// Loop to calculate and store the value of the discriminant.
	for (int i = 0; i < rows; i++)
	{
		discriminant[i] = ((array[i][1]) * (array[i][1])) - (4 * array[i][0]
							   * array[i][2]);
	}

	valueOfNumerator(array, discriminant);
}


//*******************************************************************************
//				Function Name: valueOfNumerator()								*
//				Parameters: 3D Array is passed and the Discriminant.			*
//																				*
//		The function receives the array and the Discriminant values and			*
//		uses a for loop and a counter variable to calculate and stores			*
//		the value of the Numerator and saves it in a 1D array set to the same	*
//		index as our global variable rows.										*
//		The Formula for the Numerator is: -b +- (sqrt(disciminant))				*
//																				*
//*******************************************************************************


void valueOfNumerator(int array[rows][cols], int discriminant[])
{
	double numerator[rows];
	double  numerator1[rows];

	// Loop to calculate and store the value of the Numerator.
	for (int i = 0; i < 3; i++)
	{
		numerator[i] = (array[i][1]);
		numerator1[i] = sqrt(discriminant[i]);
	}

	valueOfDenominator(array, discriminant, numerator, numerator1);
}


//*******************************************************************************
//				Function Name: valueofDenominator()								*
//				Parameters: 3D Array, Discriminant, numerator, numerator1.		*
//																				*
//		The function receives the array, Discriminant and the numerators values	*
//		and	uses a for loop and a counter variable to calculate and stores		*
//		the value of the Denominator and saves it in a 1D array set to the same	*
//		index as our global variable rows.										*
//		The Formula for the Denominator is: 2*a									*
//																				*
//*******************************************************************************


void valueOfDenominator(int array[rows][cols], int discriminant[],
						double numerator[], double numerator1[])
{
	int denominator[rows];

	// Loop to calculate and store the value of the Denominator.
	for (int i = 0; i < rows; i++)
	{
		denominator[i] = 2 * (array[i][0]);
	}

	printRoots(array, discriminant, numerator, numerator1, denominator);
}


//*******************************************************************************
//				Function Name: printRoots()										*
//				Parameters: 3D Array, Discriminant, numerator, numerator1,		*
//							and the denominator.								*
//																				*
//		The function receives the array, Discriminant, the numerators values	*
//		and the denominator then it uses a for loop and a counter variable		*
//		to calculate and stores	the value of the of the roots and saves it in	*
//		a 1D array set to the same index as our global variable rows.			*
//		The Formula for the root is: [-b +-(sqrt(discriminant)]/(2a)			*
//																				*
//*******************************************************************************


void printRoots(int array[rows][cols], int discriminant[], double numerator[],
	double numerator1[], int denominator[])
{
	double root2[rows];
	double root[rows];

	// Loop to calculate and store the value of the root(s).
	for (int i = 0; i < 3; i++)
	{
		root[i] = ((-array[i][1]) + sqrt(discriminant[i])) / (denominator[i]);
		root2[i] = ((-array[i][1]) - sqrt(discriminant[i])) / (denominator[i]);

	}

	showMeTheMatrix(array, discriminant, numerator, numerator1, denominator, root, root2);
}


//*******************************************************************************
//				Function Name: showMeTheMatrix()								*
//				Parameters: 3D Array, Discriminant, numerator, numerator1,		*
//							denominator and the roots .							*
//																				*
//		The function receives the array, Discriminant, the numerators values	*
//		the denominator and the roots.It then Display the result of the Matrix,	*
//		the numerator, denominator and the roots to the main function.			*
//																				*
//*******************************************************************************


void showMeTheMatrix(int array[rows][cols], int discriminant[], double numerator[],
	double numerator1[], int denominator[], double root[], double root2[])
{
	// Loop to Display on the screens the equation and each function.
	for (int i = 0; i < 3; i++)
	{
		cout << "\nEquation " << i + 1;
		cout << "\nA is: " << array[i][0] << ", B is: "
			<< array[i][1] << ", C is: " << array[i][2];

		cout << "\nDiscriminant: " << discriminant[i] << '\n';

		if (discriminant[i] > 0)
		{
			numerator[i] = (array[i][1]);
			numerator1[i] = sqrt(discriminant[i]);

			cout << "Numerator: " << "-" << numerator[i] << " +- " << numerator1[i] << '\n';

		}
		else if (discriminant[i] == 0)
		{
			numerator[i] = (array[i][1]);

			cout << "Numerator: " << "-" << numerator[i] << '\n';
		}
		else
		{
			numerator[i] = (array[i][1]);
			numerator1[i] = sqrt(-1 * discriminant[i]);
			cout << "Numerator: " << "-" << numerator[i] << " +- " << numerator1[i] << "i\n";
		}

		cout << "Denominator: " << denominator[i] << '\n';

		if (discriminant[i] > 0)
		{
			root[i] = (array[i][1]) / (2 * (array[i][0])) + (sqrt(discriminant[i])
						/ denominator[i]);

			root2[i] = (array[i][1]) / (2 * (array[i][0])) - (sqrt(discriminant[i])
						/ denominator[i]);
			
			cout << "There are two real roots : " << root2[i] << " and " << root[i]
				<< '\n';
		}
		else if (discriminant[i] == 0)
		{
			root[i] = (array[i][1]) / (2 * (array[i][0]));
			cout << "There is one real root: -" << root[i] << '\n';
		}
		else
		{
			root[i] = (array[i][1]) / (2 * (array[i][0]));
			root2[i] = sqrt(-1 * discriminant[i]) / denominator[i];

			cout << "There are two complex roots : -" << root[i] << " +- " << root2[i]
				<< "i\n";;

		}
		cout << "\n=====================================\n\n";
	}

	cout << "\n   My MATTRIX\n\n";

	// Loop to Display the 3D mattrix to the user. 
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << left << setw(8) << array[i][j];
		}
		cout << '\n';
	}
}