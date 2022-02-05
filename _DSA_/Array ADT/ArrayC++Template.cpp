#include <iostream>
using namespace std;


//creating Generic Array
template <class T>
class Array
{

private:
	T *A;
	int size;
	T length;

public:
	//Non Parameterized Constructor
	Array()
	{
		size = 10;
		A = new T[10];
		length = 0;
	}

	//parameterized constructor
	Array(T sz)
	{
		size = sz;
		length = 0;
		A = new T[size];
	}

	//Destructor : to release memory in Heap
	~Array()
	{
		delete[] A;
	}
	void Display();
	void Insert(T val, int index);
	T Delete(int index);

	Array::void check(){
		cout<<"check"<<endl;
	}
};

template <class T>
void Array<T>::Display()
{
	cout<<"Displaying ..."<<endl;
	cout<<length<<endl;
	for (int i = 0; i < length; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

template <class T>
void Array<T>::Insert(T val, int index)
{
	int i;
	if (index >= 0 && index <= length)
	{
		for (i = length - 1; i >= index; i--)
		{
			A[i + 1] = A[i];
		}
		A[index] = val;
		length++;
		// cout<<"Length of array is  : "<<length<<endl;
	}
}

template <class T>
T Array<T>::Delete(int index)
{   
	int i;
	if (index >= 0 && index < length)
	{
		for (i = index; i < length - 1; i++)
		{
			A[i] = A[i + 1];
		}
		length--;
		return 0;
	}
	return -1;
}

int main()
{
	// Array a =  Array(10);
	Array<float> a(10);
	a.Insert(12.4,0);
	a.Insert(14.2,1);
	a.Insert(19.8,2);
	a.Display();
	a.Delete(1);
	a.Display();
	a.Insert(22,1);
	a.Display();
	return 0;
}