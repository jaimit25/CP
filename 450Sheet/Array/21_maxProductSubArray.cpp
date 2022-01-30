// template link : https://www.codingbroz.com/fast-cpp-template-using-macros/
#include <iostream>
#include <bits/stdc++.h>
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;

#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto &(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a, b) memset(a, b, sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PERMUTE next_permutation
#define TC(t) while (t--)

using namespace std;

class Solution
{

public:
	long long maxProduct(vector<int> arr, int n)
	{
		// code here
		long long int currPro = arr[0];
		long long int maxPro = arr[0];

		for (int i = 1; i < n; i++)
		{

			if (currPro == 0)
				currPro = 1;

			currPro = currPro * (arr[i]);
			if (currPro > maxPro)
			{
				maxPro = currPro;
			}
			cout<<"Curr product : "<<currPro<<endl;
			cout<<"max product : "<<maxPro<<endl;
		}
		return maxPro;
	}
};

int main()
{

	Solution obj;
	vector<int> v;

	int sz;
	cin >> sz;

	int temp;
	for (int i = 0; i < sz; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}

	cout << obj.maxProduct(v, sz) << endl;

	return 0;
}

// Let me reason the solution.

// There are 2 possibilities - either the number of -ve numbers is even or odd.



// 1. If they are even, then obviously we would want to include all of them(in fact the whole array(unless for zeros)) to maximise the product. This is because multiplying an even number of -ve numbers would make the result +ve.



// 2. If they are odd, then we would want to exclude at most(to maximise the product) one -ve number from our product. So, now the question is, which -ve number to exclude? There are 2 possibilities - first -ve num or last -ve num.


// a. Note that, you cannot exclude a -ve number that is not the first or the last, because, if you do so, you will need to exclude all(because you are breaking the product at this point) other -ve nums following that -ve number and then that needn't result in the maximum product.


// b. Remember, that our goal is to leave out only 1 -ve number so that we can maximise our product.


// c. Note: We are leaving out one -ve number, so that we are able to make the number of -ve nums even. Having said all that, now the question is whether to exclude the first -ve num or the last -ve num in the array. We can only know the answer by trying both.


// d. By taking the product from the beginning of the array, you forcefully include the first -ve number and exclude the last -ve number


// e. vice-versa for taking the product from the end





// To further explain 2d,e, let me take an example:

// Assume the array has an odd number of -ve nums. The first -ve num is -2 and the last -ve num is -3. So the array is .....-2.......-3.......
// The maximum product can either be made of all numbers from the beginning of the array to the first non-zero number just before -3, or from the end of the array to the first non-zero number just after -2.



// This is why we are considering two possible products, one from the beginning and one from the end.



// But wait, you might be thinking, why we are still continuing to multiply even beyond -3(forward iteration) or beyond -2 (backward iteration). That's all actually waste, as the product is only going to increase in negativity beyond those points. The maximum is already updated, so this doesn't affect at all.

