// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
// A shift on s consists of moving the leftmost character of s to the rightmost position.
// For example, if s = "abcde", then it will be "bcdea" after one shift.

// Example 1:
// Input: s = "abcde", goal = "cdeab"
// Output: true


#include<bits/stdc++.h>
#define ll long long int
#define push_back pb
#define F first 
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define vvi vector<vector<int>>

using namespace std;

bool rotateString(string A , string B)
{
	if(A.size() != B.size())
            return false;
        if(A == B)      //for empty strings
            return true;
        
        int len = B.size();
        while(len--)
        {
            if(A == B)
                return true;
            A = A.substr(1) + A[0];     // one shift on A
        }x
        return false;
}
 
 
int main()
{



freopen("output.txt","w",stdout);
string A = "abcde";
string B = "cdeab";
if(rotateString(A,B)){
    cout<<"True";
}
 
 
return 0;
}
 