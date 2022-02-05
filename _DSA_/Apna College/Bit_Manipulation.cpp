#include <iostream>
#include <stdio.h>

using namespace std;

// get Bit
int getBit(int n, int i)
{
	return ((n & (1 << i)) != 0);
}

// set Bit
int setBit(int n, int i)
{
	return (n | (1 << i));
}

//clear Bit
int clearBit(int n, int i)
{
	int mask = ~(1 << i); //also called as masking
	return (mask & n);
}

//update Bit
int updateBit(int n, int i, int value)
{
	int mask = ~(1 << i); //also called as masking
	n = n & mask;
	return (n | (value << i));
}

int main()
{
	// 5 :  0101
	// over here 3 2 1 0 are the indexes for bits
	//           0 1 0 1

	cout << getBit(5, 2) << endl;
	cout << setBit(5, 1) << endl;
	cout << clearBit(5, 2) << endl;
	cout << updateBit(5, 1, 1) << endl;

	return 0;
}