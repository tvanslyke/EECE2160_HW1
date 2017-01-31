/*
 * problem_4.cpp
 *
 *  Created on: Jan 30, 2017
 *      Author: tim
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;


int add_mult_div_thingy(int a, int b, int & prod, int & quotient)
{
	prod = a * b;
	quotient = a / b;
	return a + b;
}


int main4(void)
{
	int prod, quot;
	int a, b;
	cout << "Enter two numbers so we can do math on them and stuff." << endl;
	cout << "It would probably be best if you separated the numbers by spaces...\n>>> " << std::flush;
	cin >> a >> b;
	cout << "The sum is: " << add_mult_div_thingy(a, b, prod, quot) << endl;
	cout << "The product is: " << prod << endl;
	cout << "The quotient is: " << quot << endl;
	return 0;
}

