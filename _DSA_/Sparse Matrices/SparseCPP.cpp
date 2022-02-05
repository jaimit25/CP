#include <iostream>
using namespace std;

class Element
{
public:
	int i;
	int j;
	int x;
};

class Sparse
{
private:
	int m;
	int n;
	int num;
	Element *ele;

public:
	Sparse(int m, int n, int num)
	{
		this->m = m;
		this->n = n;
		this->num = num;
		ele = new Element[this->num];
	}
	~Sparse()
	{
		delete[] ele;
	}

	//operator overloading in c++ can be done using member of friend function
	friend istream &operator>>(istream &is, Sparse &s);
	friend ostream &operator<<(ostream &os, Sparse &s);
	Sparse operator+(Sparse &s);
};
//instead of calling function we can use instertion operator cin
// void read()
// {
// 	cout << "Enter Non Zero Elements" << endl;
// 	for (int i = 0; i < num; i++)
// 	{
// 		cin >> ele[i].i >> ele[i].j >> ele[i].x;
// 	}
// }
//we dont need scope resolution because they are friend function
istream &operator>>(istream &is, Sparse &s)
{
	cout << "Enter Non Zero Elements" << endl;
	for (int i = 0; i < s.num; i++)
	{
		cin >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;
		// is >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;
	}
	return is;
}

//instead of calling function we can use extraction operator cout
// void display()
// {
// 	int k = 0;
// 	for (int i = 0; i < m; i++)
// 	{
// 		for (int j = 0; j < n; j++)
// 		{
// 			if(ele[k].i == i && ele[k].j == j){
// 				cout<<ele[k++].x<<" ";
// 			}
// 			else{
// 				cout<<"0 ";
// 			}
// 		}
// 		cout<<endl;
// 	}
// }
//we dont need scope resolution because they are friend function
ostream &operator<<(ostream &os, Sparse &s)
{
	int k = 0;
	for (int i = 0; i < s.m; i++)
	{
		for (int j = 0; j < s.n; j++)
		{
			if (s.ele[k].i == i && s.ele[k].j == j)
			{
				cout << s.ele[k++].x << " ";
				// os << s.ele[k++].x << " ";
			}
			else
			{
				cout << "0 ";
				// os << "0 ";
			}
		}
		cout << endl;
	}

	return os;
}

Sparse Sparse::operator+(Sparse &s)
{
	//&s  means we are taking extra matrix and we have our own matrix as well
	int i, j, k;
	if (m != s.m && n != s.n)
	{
		return Sparse(0, 0, 0);
	}
	Sparse *sum = new Sparse(m, n, num + s.num);
	i = j = k = 0;
	while (i < num && j < s.num)
	{
		if (ele[i].i < s.ele[i].i)
		{
			sum->ele[k++] = ele[i++];
		}
		else if (ele[i].i > s.ele[i].i)
		{
			sum->ele[k++] = s.ele[j++];
		}
		else
		{
			if (ele[i].j < s.ele[i].j)
			{
				sum->ele[k++] = ele[i++];
			}
			else if (ele[i].j > s.ele[i].j)
			{
				sum->ele[k++] = s.ele[j++];
			}
			else{
				sum->ele[k] = ele[i];
				sum->ele[k++].x = ele[i++].x + s.ele[j++].x;
			}
		}
	}

	for (; i < num; i++)
		sum->ele[k++] = ele[i];
	for (; j < s.num; j++)
		sum->ele[k++] = s.ele[j];
	// sum->m = m;
	// sum->n = n;
	sum->num = k;

	return *sum ;
}

// };

int main()
{

	Sparse s1(5, 5, 5);
	// s1.read();
	//instead of read we can use cin
	cin >> s1;
	// s1.display();
	//instead of display cout we can use cout
	cout << s1 << endl;

	Sparse s2(5, 5, 5);
	// s2.read();
	//instead of read we can use cin
	cin >> s2;
	// s2.display();
	//instead of display cout we can use cout
	cout << s2 << endl;


	Sparse sum = s1 + s2;
	cout<<sum<<endl;
}