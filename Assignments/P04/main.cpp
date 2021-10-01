/*****************************************************************************
/			Assignment #4													 *
/			Name: Loic Konan												 *
/			Data Structures: 11/06/2020										 *
/																			 *
/*****************************************************************************

/*****************************************************************************
  The objective of this homework is to practice, reinforce and use pointers. *
  In this program we will try to find how many Females and males lives in	 *
  Tiny Ville base on the Social Security Numbers.							 *
  We Will first creates a Matrix by declaring a 2D Array and utilizing		 *
  dynamically allocated memory to allow the user to set the dimensions of	 *
  the Matrix. The array will be passed to a function that will categorize    *
  the SSN #'s into blocks and add how many SSN #'s are within that number    *
  block. Afterwards, the array is sent to another function that will		 *
  determine if the SSN #'s belong to a Male or a Female and then Display     *
  the number of Habitants in Tiny Ville.				 					 *
																			 *
/*****************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;

// Funtion Prototype to determine the number of women/men in Tiny Ville.
void Genders(int** Array, int Row, int Column);

// Funtion Prototype to Sumarize the numbers of Social Security Numbers.
void Summary_SSN(int** Array, int Row, int Column);

int main()
{
	int Rows, Cols;

	// Variables for setting a range for our random values
	int MinVal = 1000;
	int MaxVal = 5999;

	cout << "Please enter the number of Rows and Columns for the Matrix: ";
	cin >> Rows >> Cols;

	// While loop to make sure it Always a Square Matrix.
	while (Rows != Cols)
	{
		cout << "Please try to enter a square matrix: ";
		cin >> Rows >> Cols;
	}

	int** Matrix = new int* [Rows];

	// Dynamically allocate memory of size for each row
	for (int i = 0; i < Rows; i++)
	{
		Matrix[i] = new int[Rows];
	}

	for (int j = 0; j < Cols; j++)
	{
		Matrix[j] = new int[Cols];
	}

	// Dynamically allocate memory of size for each column
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			// setting our rand function to fill the matrix with numbers in the desired range
			int number = rand() % (MaxVal - MinVal + 1) + MinVal;
			Matrix[i][j] = number;
		}
	}

	cout << "\n============================================================\n";
	cout << "		Matrix ("<< Rows << " x " << Cols << ")\n";
	cout << "============================================================\n";
	
	// Displaying the randomly generated matrix.
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << "        " << Matrix[i][j] << "  ";
		}
		cout << '\n';
	}

	Summary_SSN(Matrix, Rows, Cols);
	Genders(Matrix, Rows, Cols);
	cout << "\n============================================================\n";

	// Releasing the dynamic memory
	delete[] Matrix;

	return 0;
}



/****************************************************************************
	Function Name: Summary_SSN												*
	Paramters: int **Array, int Random, int Column							*
																			*
	This function receives the pointer array with the dynamically allocated *
	memory and variables necessary to read the Matrix.						*
	In this funtion, we will summarizes the SSNs in Tiny Ville				*
																			*
*****************************************************************************/
void Summary_SSN(int** Array, int Random, int Column)
{
	int total = Random * Column;

	int SSN1 = 0;
	int SSN2 = 0;
	int SSN3 = 0;
	int SSN4 = 0;
	int SSN5 = 0;

	for (int i = 0; i < Random; i++)
	{
		for (int k = 0; k < Column; k++)
		{
			if (Array[i][k] > 999 && Array[i][k] < 2000)
			{
				SSN1++;
			}

			if (Array[i][k] > 1999 && Array[i][k] < 3000)
			{
				SSN2++;
			}

			if (Array[i][k] > 2999 && Array[i][k] < 4000)
			{
				SSN3++;
			}

			if (Array[i][k] > 3999 && Array[i][k] < 5000)
			{
				SSN4++;
			}

			if (Array[i][k] > 4999 && Array[i][k] < 6000)
			{
				SSN5++;
			}
		}
	}

	cout << "\n============================================================\n";
	cout << "The following summarizes the SSNs in Tiny Ville:\n\n";
	cout << "		SSN: 1000's = " << SSN1 << '\n';
	cout << "		SSN: 2000's = " << SSN2 << '\n';
	cout << "		SSN: 3000's = " << SSN3 << '\n';
	cout << "		SSN: 4000's = " << SSN4 << '\n';
	cout << "		SSN: 5000's = " << SSN5 << '\n';
	cout << "\nThe total # of habitants in Tiny Ville is: " << total << '\n';
}



/****************************************************************************
	Function Name: Genders												    *
	Paramters: int **Array, int Random, int Column							*
																			*
	This function receives the pointer array with the dynamically allocated *
	memory and variables necessary to read the Matrix.In this function,     *
	we will set all EVEN SSN�s to Women and all ODD SSN�s with men.			*
	Then we will display the number of residents in Tiny Ville				*
																			*
*****************************************************************************/
void Genders(int** Array, int Random, int Column)
{
	int Male = 0;
	int Female = 0;
	int total = Random * Column;

	for (int i = 0; i < Random; i++)
	{
		for (int k = 0; k < Column; k++)
		{
			// If Even.
			if (Array[i][k] % 2 == 0)
			{
				Female++;
			}

			// If Odd.
			else
				Male++;
		}
	}
	cout << "\n============================================================\n";
	cout << "The following summarizes the Genders in Tiny Ville.\n\n";
	cout << "The total # of residents in Tiny Ville is: " << total << '\n';
	cout << "Tiny Ville has = " << Female << " Women.\n";
	cout << "Tiny Ville has = " << Male << " Men.\n";
}
