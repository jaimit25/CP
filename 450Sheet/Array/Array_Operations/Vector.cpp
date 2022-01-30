#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
};

void display(vector<int> &v)
{

	// for (int i = 0; i < v.size(); i++)
	// {
	// 	// cout << v[i] << " ";
	// 	//they both are same
	// 	cout << v.at(i) << " ";
	// }
	for (auto it : v)
	{
		cout << it << " ";
	}
	cout << endl;
}

int main()
{

	// Solution obj;

	// vector<int> vec1;
	// int element;
	// for (int i = 0; i < 4; i++)
	// {
	// 	cin >> element;
	// 	vec1.push_back(element);
	// }

	// display(vec1);
	// vec1.pop_back();
	// display(vec1);

	// //to insert an element using an iterator
	// //to create an iterator
	// vector<int> :: iterator iter = vec1.begin(); //pointing iterator at first element
	// // iter + 1 will point at second element in an Array
	// vec1.insert(iter ,566);
	// display(vec1);

	vector<vector<int> > v;
	vector<int> temp;

	int sz;
	cin >> sz;

	int a, b;

	for (int i = 0; i < sz; i++)
	{
		cout << "Enter value : ";
		cin >> a >> b;
		temp.push_back(a);
		temp.push_back(b);
		cout << endl;
		v.push_back(temp);
		temp.pop_back();
		temp.pop_back();
	}

	cout << "**********" << endl;
	for (auto it : v)
	{
		cout << it[0] << " " << it[1] << endl;
	
	}
	cout << "**********" << endl;

	return 0;
}
