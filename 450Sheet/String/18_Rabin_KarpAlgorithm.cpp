// template link : https://www.codingbroz.com/fast-cpp-template-using-macros/
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <climits>
#include <algorithm>
#define d 256

using namespace std;

class Solution
{

public:
	// brute approach
	// bool check(char *text, char *pattern, int s, int e)
	// {
	// 	int k = 0;
	// 	int i = s;

	// 	for (int i = s, k = 0; i <= e; i++, k++)
	// 	{
	// 		if (text[i] != pattern[k])
	// 		{
	// 			return false;
	// 		}
	// 	}
	// 	return true;
	// }

	// bool search(char pat[], char txt[], int p, int t)
	// {
	// 	// 17-4 = 13 skipping last few characters
	// 	int i = 0;
	// 	while (i <= t - p)
	// 	{
	// 		// cout << "value of i  is : " << i << endl;
	// 		bool ans = check(txt, pat, i, (i + p - 1));
	// 		if (ans)
	// 			return true;
	// 		i++;
	// 	}
	// 	return false;
	// }

	// void search(char pat[], char txt[], int q)
	// {
	//     int M = strlen(pat);
	//     int N = strlen(txt);
	//     int i, j;
	//     int p = 0; // hash value for pattern
	//     int t = 0; // hash value for txt
	//     int h = 1;

	//     // The value of h would be "pow(d, M-1)%q"
	//     for (i = 0; i < M - 1; i++)
	//         h = (h * d) % q;

	//     // Calculate the hash value of pattern and first
	//     // window of text
	//     for (i = 0; i < M; i++)
	//     {
	//         p = (d * p + pat[i]) % q;
	//         t = (d * t + txt[i]) % q;
	//     }

	//     // Slide the pattern over text one by one
	//     for (i = 0; i <= N - M; i++)
	//     {

	//         // Check the hash values of current window of text
	//         // and pattern. If the hash values match then only
	//         // check for characters one by one
	//         if ( p == t )
	//         {
	//             bool flag = true;
	//             /* Check for characters one by one */
	//             for (j = 0; j < M; j++)
	//             {
	//                 if (txt[i+j] != pat[j])
	//                 {
	//                   flag = false;
	//                   break;
	//                 }
	//                   if(flag)
	//                   cout<<i<<" ";

	//             }

	//             // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]

	//             if (j == M)
	//                 cout<<"Pattern found at index "<< i<<endl;
	//         }

	//         // Calculate hash value for next window of text: Remove
	//         // leading digit, add trailing digit
	//         if ( i < N-M )
	//         {
	//             t = (d*(t - txt[i]*h) + txt[i+M])%q;

	//             // We might get negative value of t, converting it
	//             // to positive
	//             if (t < 0)
	//             t = (t + q);
	//         }
	//     }
	// }
};

// hash function
int hashFunction(char *text, int s, int e)
{
	int k = 0;
	int hash_code = 0;
	int i = s;
	int n = e - s + 1;
	// cout << "n value is : " << n << endl;
	for (int i = s, k = n - 1; i <= e; i++, k--)
	{
		hash_code = hash_code + (int)text[i] * pow(10, k);
	}
	return hash_code;
}

bool rabinKarp(char *text, int t, int hashCode, int p)
{
	// 17-4 = 13 skipping last few characters
	int i = 0;
	while (i <= t - p)
	{
		// cout << "value of i  is : " << i << endl;
		// bool ans = check(txt, pat, i, (i + p - 1));
		int code = hashFunction(text, i, i + p - 1);
		if (code == hashCode)
			return true;
		i++;
	}
	return false;
}

int main()
{

	// int p = 4;
	// int t = 17;

	// cin >> p >> t;
	// char *text = new char[t];
	// char *pattern = new char[p];
	//  cin >> noskipws >> a[i]; // TO TAKE SPACE AS INPUT
	// char text[] = "THIS IS TEST TEXT";
	// char pattern[] = "TEST";

	// Solution obj;
	// cout << obj.search(pattern, text, p, t) << endl;
	// int q = 101;
	// obj.search(pattern, text, q);

	char pattern[] = "edb";
	// char text[] = "ccaccedb"; //rabin karp function returns true
	char text[] = "ccacced"; //rabin karp function returns false
	int t = 8;
	int p = 3;
	int hashCode = hashFunction(pattern, 0, 2);
	cout << rabinKarp(text, t, hashCode, p) << endl;

	return 0;
}

// 4 17
// THIS IS TEST TEXT
// TEST
