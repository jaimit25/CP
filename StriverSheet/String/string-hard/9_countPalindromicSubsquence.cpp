//Gfg solution uses DP Approach so this solution wont work there

// Input: 
// Str = "aab"
// Output: 
// 4
// Explanation:
// palindromic subsequence are :"a", "a", "b", "aa"



#include<bits/stdc++.h>
#define ll long long int
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

void print(vector<string> s){
    for(auto it  :s){
        cout<<it << " ";
    }
    cout<<endl;
}

bool isPalindrome(string s){
    string temp = s;
    reverse(temp.begin(),temp.end());
    return temp==s;
}



void helper(string &s, string &temp, int i, vector<string> &strs){

    int n = s.size();

    if(i == n){
        // do not insert empty string
        if(temp != "") strs.push_back(temp);
        
        return;
    }
    
    //add the current index 
    temp.push_back(s[i]);
    helper(s,temp,i+1,strs);

    //dont add the current index value
    temp.pop_back();
    helper(s,temp,i+1,strs);

}


long long int  countPS(string &str)
{
    string temp="";
    long long int count = 0; 
    vector<string> strs;

    helper(str,temp,0,strs);
    print(strs);
    cout<<strs.size()<<endl;
    for(auto it : strs){
        if(isPalindrome(it))count++;
    }

    return count;
}
 
 
int main()
{

string s = "aab";
cout<<countPS(s)<<endl;
 
 
return 0;
}
 