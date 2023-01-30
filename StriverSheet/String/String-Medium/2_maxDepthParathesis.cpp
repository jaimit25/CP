// A string is a valid parentheses string (denoted VPS) if it meets one of the following:
// It is an empty string "", or a single character not equal to "(" or ")",
// It can be written as AB (A concatenated with B), where A and B are VPS's, or
// It can be written as (A), where A is a VPS.
// We can similarly define the nesting depth depth(S) of any VPS S as follows:
// depth("") = 0
// depth(C) = 0, where C is a string with a single character not equal to "(" or ")".
// depth(A + B) = max(depth(A), depth(B)), where A and B are VPS's.
// depth("(" + A + ")") = 1 + depth(A), where A is a VPS.

//IMPORTANT :  For example, "", "()()", and "()(()())" are VPS's (with nesting depths 0, 1, and 2), and ")(" and "(()" are not VPS's.

// Given a VPS represented as string s, return the nesting depth of s.
#include<bits/stdc++.h>
#define vi             vector <int>


using namespace std;
 int maxDepth(string s) {
        int cur = 0; 
        int mx =0 ; 
        for(auto it:s){
            if(it=='('){
                cur++;
                mx = max(mx,cur);
            }
            else if(it==')')cur--;
        }
        return mx;
    }

int main()
{
// string s = "(1+(2*3)+((8)/4))+1";
// string s = "";
string s = "()";
cout<<maxDepth(s)<<endl;
 
return 0;
}
 