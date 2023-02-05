//using Z algorithm
#include <bits/stdc++.h>
#define ll long long int
#define F first
#define S second
#define pb push_back
#define si set<int>
#define vi vector<int>
#define pii pair<int, int>
#define vpi vector<pii>
#define vpp vector<pair<int, pii>>
#define mii map<int, int>
#define mpi map<pii, int>
#define spi set<pii>
#define vvi vector<vector<int>>

using namespace std;

// program to check if string is palindrome
bool ispalindrome(string &s) {
  string rev = s;
  reverse(rev.begin(), rev.end());
  return rev == s;
}

void print(vi &a) {
  for (auto it : a) {
    cout << it << " ";
  }
  cout << endl;
}

// Approach 1
// string shortestPalindrome(string &s) {
// Step's
// 1) find the longest palindrome in the s string which compulsory has (0 index)
//     ie for "aabdaaa"
// 	   (This all substring has to be checked "a" , "aa" , "aab" ,"aabd" ,
// "aabda" ,"aabdaa" , "aabdaaa" ) 2) so if first x (ie. 4) characters are
// forming a palindromic substring ie. X X X X ...
//    then the remaining character has to be reversed.
// 3) The reverse string has to be attached in the front of string s to form a
// shortest palindrome 4) Example "abb" 5) The longest palindrome with first
// char included is "a" 6) so reverse the remaining string "bb" -> "bb" (same
// for this case) 7) add reverse string to the s, ie. ans =
// rev_of_remaining_char_from(s) + s;

// string ans="";
// string temp=s;
// int n = s.size();

// //base case
// if(n == 1) return s;
// if(ispalindrome(s)) return s;

// int mxm = 0 ;

// for(int i = n-1 ; i>= 0 ; i--){
// 	// getlong_palindrome : return true is temp is a palindrome
// 	if(isalindrome(temp)){
// 		// the whole string is palindrome
// 		int sz = temp.size();
// 		mxm = max(mxm,sz); // store the length of the lonest palindrome
// 		break;
// 	}
// 	temp.pop_back();
// }
// string rev = s;
// reverse(rev.begin(),rev.end());
// // cout<<mxm<<endl;

// rev = rev.substr(0,n-mxm);
// ans = rev + s;

// return ans;
// }

// Approach 2
// string shortestPalindrome(string &s) {

// // Example:
// // s = dedcba. Then r = abcded and I try these overlays (the part in (...) is
// the prefix I cut off, I just include it in the display for better
// understanding):
// //   s          dedcba
// //   r[0:]      abcded    Nope...
// //   r[1:]   (a)bcded     Nope...
// //   r[2:]  (ab)cded      Nope...
// //   r[3:] (abc)ded       Yes! Return abc + dedcba

// 	string rev = s;
// 	int n = s.size();

// 	//base case
//     if(n == 1) return s;
//     if(ispalindrome(s)) return s;

// 	reverse(rev.begin(),rev.end());

// 	string temp;
// 	for(int i = 1 ; i <= n ;i++){
// 		temp = rev.substr(0,i);
// 		string test = temp+s;
// 		if(ispalindrome(test)) return temp+s;
// 	}

// 	return "";

// }





  string shortestPalindrome(string & s) {

    //  if (s == "")
    //   return s;
    // int len = s.length();
    // string r = s;
    // reverse(r.begin(), r.end());
    // string s1 = s + "$" + r;
   

    // int L, R;
    // int m = s1.size();
    // vector<int> z(m, 0);
    // L = R = 0;

    // for (int i = 0; i < m; i++) {
    //   if (i > R) {
    //     L = R = i;
    //     while (R < m && s1[R] == s1[R - L])
    //       R++;
    //     z[i] = R - L;
    //     R--;
    //   } else {

    //     int k = i - L;

    //     if (z[k] < R - i + 1)
    //       z[i] = z[k];
    //     else {
    //       L = i;
    //       while (R < m && s1[R] == s1[R - L])
    //         R++;
    //       z[i] = R - L;
    //       R--;
    //     }
    //   }

    //   if (i > len && i + z[i] == m) // found answer
    //   {
    //   	print(z);
    //   	cout<<s1.substr(len + 1, i - len - 1) + s<<endl;
    //     return s1.substr(len + 1, i - len - 1) + s;
    //   }
    // }

    // return "";
  }

  int main() {



    // string s = "aacecaaa";
    // string s = "abcd";
    string s = "abb";

    string ans = shortestPalindrome(s);
    cout << ans << endl;

    return 0;
  }
