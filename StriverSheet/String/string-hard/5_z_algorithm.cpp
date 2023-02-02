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
 

void print(vi &a){
	for(auto it : a){
		cout<<it<< " ";

	}
	cout<<endl;
}


//Naive Approach
// vector <int> search(string pat, string txt)
// {
//         int sz = pat.size();
//         int n = txt.size();
//         vector<int> in;
//         for(int i = 0 ; (i+sz-1) < n ; i++){
//             string curr = txt.substr(i,sz);
//             if(curr == pat) in.push_back(i+1);
//         }
//         if(in.size() == 0 ) in.push_back(-1);
//         return in;
// }

 vector <int> search(string pat, string txt)
{
	   
    vector<int > ans ;
	vector<int > z;

	//creating a new  string which follows the pattern  : pat + $ + text
	string s = pat + '$' + txt;

	for(int i = 0 ; i < s.size() ; i++){
		if(i <= pat.size()) z.push_back(0);
		else{
			int l = 0 ;
			int r = i ;
				// finding the length of the longest prefix for current index i 
				while(s[l] == s[r] && r < s.size()){
					l++;
					r++;
				
				}
				z.push_back(l);
			}
		}
	

	for(int i = 0; i  < s.size() ; i++){
		if(pat.size() == z[i]) ans.push_back(i-pat.size());
	}



	if(ans.size() == 0) ans.push_back(-1);
	return ans;


}



 
int main()
{

string t = "batmanandrobinarebat";
string p = "bat";
vi ans = search(p,t);
print(ans);
 
 
return 0;
}
 