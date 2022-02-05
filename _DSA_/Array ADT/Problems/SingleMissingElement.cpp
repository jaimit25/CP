#include <iostream>
using namespace std;

class Array
{
public:
	int *A;
	int size;
	int length;

public:
	Array()
	{
		A = new int[10];
		size = 10;
		length = 0;
	}

	Array(int sz)
	{
		size = sz;
		length = 0;
		A = new int[sz];
	}

	void Append(int element)
	{
		if (length < size)
		{
			A[length] = element;
			length++;
			// cout << "value of length is : " << length << endl;
		}
		else
		{
			cout << "!! Array is Full" << endl;
		}
	}
	void Display()
	{
		for (int i = 0; i < length; i++)
		{
			cout << A[i] << " ";
		}
		cout << endl;
	}

	void MissingElement()
	{
		int l = A[0];
		int h = A[size];
		int diff = l - 0;
		for(int i = 0 ; i < length ; i++){
			if(A[i]-i != diff){
				cout<<"missing element is  : "<< i+ diff<<endl;
				break;
			}
		}
	}
};

int main()
{

	Array a(11);
	int val = 0;
	int chk = 0;
	cout << "Enter The Elements" << endl;
	while (a.length < a.size)
	{
		cin >> val;
		a.Append(val);
	}
	cout << "Length of Array is : " << a.length << endl;
	a.Display();
	a.MissingElement();

	return 0;
}