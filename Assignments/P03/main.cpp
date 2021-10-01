/*
	Loic Konan
	Homework 3 about pointers!!!
*/

#include<iostream>
#include<fstream>
using namespace std;


int main()
{
	ofstream outfile;
	outfile.open("output.txt");
	outfile << "Loic Konan: \n\n";

	outfile << "		  Homework 3 about pointers!!!\n\n";


	outfile << "          This is Exercise #1 Below!!!! \n\n";

	int a = 10, b = 10;
	int* p1, * p2, * p3;

	p3 = NULL;
	p1 = &a;
	p2 = &b;

	outfile << "          1) a. What's the value of the expression (p1 = = p2)?\n"
			<< "               (true/false)\n";

	if (p1 == p2)
	{
		outfile << "\n          The answer is: True\n";
	}
	else
	{
		outfile << "\n          The answer is: False\n";
	}


	outfile << "\n\n\n          1) b. Showing Step by Step after *p1 = *p2 + 1"
		" executing: \n\n";

	outfile << "            p1 -> a                      p2 -> b\n\n";
	outfile << "           *p1 = " << *p1 << "                     *p2 = "
			<< *p2 << " \n\n";

	outfile << "           *p1 = (*p2 + 1) = " << (*p2 + 1)
			<< "         *p2 = " << *p2 << "\n\n\n";



	outfile << "          1) c. After executing the following statements \n"
			<< "           what is the value of *p1 and *p2?\n\n";
	outfile << "\n          p3 = NULL\n          p3 = p1\n"          
			<< "          p1 = p2\n          p2 = p1\n\n";

	p3 = p1;
	p1 = p2;
	p2 = p1;
	
	outfile << "          *p1 = _____?_____ *p2 = _____?_____ \n\n";
	outfile << "          *p1 = " << *p1
			<< "          *p2 = " << *p2 << "\n\n\n\n";


	outfile << "          1) d. Write a statement that adds the integers point\n"
		"           to by p1 and p2 and puts the sum in an integer "
		"variable j.\n\n";

	outfile << "          The statement is: int j = (*p1 + *p2)\n\n";
	outfile << "                            int j = (*p1 + *p2) =  "
		<< (*p1 + *p2) << "\n\n\n";



	// The second part of the homework.

	outfile << "\n\n				This is Exercise #2 Below!!!! \n\n";

	outfile << "      Below you will find to important elements, an array and a\n"
			<< "      pointer named NUMBER. At the beginning of each one of the\n"
		    << "      entries (a, b, c, d, e, f, g, h) the pointer is pointing\n"
			<< "      at the beginning of the array. With this given info, for each\n"
			<< "      one of the cases ENTRIES complete the table below and type the\n"
			<< "      corresponding output under the Value Here column.\n\n";
	outfile << "           This's the array: int number[] = { 5, 9, 1, 2, 3, 4 }\n\n";

	int number[] = { 5, 9, 1, 2, 3, 4 };

	outfile << "              Entry               Value HERE\n\n";

	outfile << "              *number              " << *number << "\n\n";

	outfile << "              *(number + 5)        " << *(number + 5) << "\n\n";

	outfile << "              (*number + 2)        " << (*number + 2) << "\n\n";

	outfile << "              (*number + 5)        " << (*number + 5) << "\n\n";

	outfile << "              *(number + 1)        " << *(number + 1) << "\n\n";

	outfile << "              *(number + 0)        " << *(number + 0) << "\n\n";

	outfile << "              *(number + 2)        " << *(number + 2) << "\n\n";

	outfile << "              (*number + 1)        " << (*number + 1) << "\n\n";

	outfile.close();

	return 0;
}