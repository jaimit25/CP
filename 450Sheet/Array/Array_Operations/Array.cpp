#include <iostream>
using namespace std;

class Array
{

private:
	int size;
	int *A; //Array
	int i;

public:
	Array();
	void display();
	void update(int, int);
	void add(int);
	int del();
	int l_search(int);
	int b_search(int);
	int rbinary_search(int, int, int);
	int get_elemnts_len();
};

Array::Array() : i(0)
{
	// cout << "i : " << i << endl;

	cout << "Enter size of Array : ";
	cin >> size;
	cout << endl;
	A = new int[size];
	cout << "Size of Array is : " << size << endl;
}
int Array::get_elemnts_len()
{
	return i - 1;
}

void Array::display()
{
	for (int j = 0; j < i; j++)
	{
		cout << A[j] << " ";
	}
	cout << endl;
}

void Array::update(int val, int index)
{
	if (index > size - 1 || index < 0)
	{
		cout << "invalid index" << endl;
	}
	else
	{
		A[index] = val;
	}
}

void Array::add(int val)
{
	// cout << " value of i : " << i << endl;
	// cout << " value of (size -1) : " << size - 1 << endl;
	//0   4
	if (i > (size - 1))
	{
		cout << "No space " << endl;
	}
	else
	{
		A[i] = val;
		i++;
	}
}

int Array::del()
{
	int val;
	if (i == 0)
	{
		cout << "There is nothing to Delete " << endl;
		return -1;
	}
	val = A[i - 1];
	i--;
	return val;
}

int Array::l_search(int vals)
{
	for (int j = 0; j < i; j++)
	{
		if (A[j] == vals)
		{
			return j;
		}
	}
	return -1;
}

int Array::b_search(int vals)
{

	int l, h, m;

	l = 0;
	h = i - 1;
	m = 0;
	while (l <= h)
	{
		m = (l + h) / 2;
		if (A[m] == vals)
		{
			//val found
			return m;
		}
		else if (vals < A[m])
		{
			//left side
			h = m - 1;
		}
		else if (vals > A[m])
		{
			//right side
			l = m + 1;
		}
	}
	return -1;
}
int Array::rbinary_search(int l, int h, int vals)
{
	static int mid = 0;
	mid = (l + h) / 2;
	if (l <= h)
	{

		if (vals > A[mid])
		{
			//right side
			return rbinary_search(mid + 1, h, vals);
		}
		else if (vals < A[mid])
		{
			//left side
			return rbinary_search(l, mid - 1, vals);
		}
	}
	else
	{
		return -1;
	}
	if (A[mid] == vals)
	{
		return mid;
	}
	return -1;
}

int main()
{
	int run;
	Array a;
	a.add(1);
	a.add(2);
	a.add(3);
	a.add(4);
	a.add(5);
	a.display();
	int val = a.del();
	cout << "Element deleted : " << val << endl;
	a.display();
	cout << "Value found at index(Linear Search) : " << a.l_search(3) << endl;
	cout << "Value found at index(Binary search) : " << a.b_search(4) << endl;
	cout << "Value found at index(Recursive Binary search) : " << a.rbinary_search(0, a.get_elemnts_len(), 90) << endl;

	return 0;
}