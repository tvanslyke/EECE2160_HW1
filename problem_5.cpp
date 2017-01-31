/*
 * problem_5.cpp
 *
 *  Created on: Jan 30, 2017
 *      Author: tim
 */

#include <iostream>
using std::cout;
using std::endl;

/**
 * Count odds recursively.
 */
size_t count_odds(int * arr, size_t len)
{
	if(len == 1)
	{
		return (size_t)(arr[0] & 1);
	}
	else
	{
		size_t half_len = len / 2;
		return count_odds(arr, half_len) + count_odds(arr + half_len, len - half_len);
	}
}

int main5(void)
{
	int arr[] ={5, 7, 2, 1, 3};
	cout << "There are " << count_odds(arr, 5) << " odd numbers in the array." << endl;
	return 0;
}

